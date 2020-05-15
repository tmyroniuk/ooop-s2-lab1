#include "listmodel.h"

template <typename T>
ListModel<T>::ListModel(QObject *parent)
    : QAbstractListModel(parent)
    , list(new LinkedRealisation<T>)
{
}

template<typename T>
ListModel<T>::~ListModel()
{
    if(list) delete list;
}

template <typename T>
int ListModel<T>::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return list->size() + 1;
}

template <typename T>
QVariant ListModel<T>::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(role == Qt::DisplayRole) {
        if(index.row() == 0) return QString("<Head>");
        else return Generator<T>::to_qstring(*(list->begin() + index.row() - 1));
    } else if(role == RandomRole) {
        return Generator<T>::to_qstring(Generator<T>::rand_val());
    }
    return QVariant();
}

template<typename T>
bool ListModel<T>::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::DisplayRole) {
        if(!index.isValid())
            return false;
        *(list->begin() + index.row() - 1) = Generator<T>::concrete_val(value.toString().toStdString());
        return true;
    } else if(role == SortRole) {
        switch (value.toInt()) {
            case 0: list->setSortAlgo(new QuickSort<T>); break;
            case 1: list->setSortAlgo(new InsertionSort<T>); break;
            case 2: list->setSortAlgo(new MergeSort<T>); break;
        }
        return false;
    } else if(role == ListRole) {
        beginResetModel();
        if(list) delete list;
        switch (value.toInt()) {
            case 0: list = new LinkedList<T>; break;
            case 1: list = new ArrayList<T>; break;
            case 2: list = new VectorList<T>; break;
        }
        endResetModel();
        return true;
    }
    return false;
}

template <typename T>
bool ListModel<T>::insertRows(int row, int count, const QModelIndex &parent)
{
    if(row > list->size())
        return false;

    beginInsertRows(parent, row, row + count - 1);
    for(int i = 0; i < count; i++) {
        list->insert(list->begin() + row + i - 1, T());
    }
    endInsertRows();
    return true;
}

template <typename T>
bool ListModel<T>::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row == 0 || row > list->size())
        return false;

    beginRemoveRows(parent, row, row + count - 1);
    for(int i = 0; i < count; i++) {
        list->extract(list->begin() + row - 1);
    }
    endRemoveRows();
    return true;
}

template<typename T>
void ListModel<T>::clear()
{
    beginResetModel();
    while(!list->empty())
        list->extract(list->begin());
    endResetModel();
}

template<typename T>
void ListModel<T>::sort()
{
    beginResetModel();
    list->sort();
    endResetModel();
}
