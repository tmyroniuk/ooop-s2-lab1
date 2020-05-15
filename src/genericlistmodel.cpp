#include "genericlistmodel.h"

#include <QDebug>

template <typename T>
BaseList<T>* GenericListModel::list = new LinkedList<T>;
int GenericListModel::type = 0;
int GenericListModel::realisation = 0;

GenericListModel::GenericListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

GenericListModel::~GenericListModel()
{
    switch(type) {
        case 0: delete list<int>; break;
        case 1: delete list<double>; break;
        case 2: delete list<std::string>; break;
        case 3: delete list<IPv4>; break;
        case 4: delete list<IPv6>; break;
        case 5: delete list<MAC>; break;
    }
}

int GenericListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    switch(type) {
        case 0: return list<int>->size() + 1;
        case 1: return list<double>->size() + 1;
        case 2: return list<std::string>->size() + 1;
        case 3: return list<IPv4>->size() + 1;
        case 4: return list<IPv6>->size() + 1;
        case 5: return list<MAC>->size() + 1;
    }
    return 0;
}

QVariant GenericListModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole) {
        if (!index.isValid()) return QVariant();
        if(index.row() == 0) return QString("<Head>");
        else switch(type) {
            case 0: return Generator<int>::to_qstring(*(list<int>->begin() + index.row() - 1));
            case 1: return Generator<double>::to_qstring(*(list<double>->begin() + index.row() - 1));
            case 2: return Generator<std::string>::to_qstring(*(list<std::string>->begin() + index.row() - 1));
            case 3: return Generator<IPv4>::to_qstring(*(list<IPv4>->begin() + index.row() - 1));
            case 4: return Generator<IPv6>::to_qstring(*(list<IPv6>->begin() + index.row() - 1));
            case 5: return Generator<MAC>::to_qstring(*(list<MAC>->begin() + index.row() - 1));
        }
    } else if(role == RandomRole) switch(type) {
        case 0: return Generator<int>::to_qstring(Generator<int>::rand_val());
        case 1: return Generator<double>::to_qstring(Generator<double>::rand_val());
        case 2: return Generator<std::string>::to_qstring(Generator<std::string>::rand_val());
        case 3: return Generator<IPv4>::to_qstring(Generator<IPv4>::rand_val());
        case 4: return Generator<IPv6>::to_qstring(Generator<IPv6>::rand_val());
        case 5: return Generator<MAC>::to_qstring(Generator<MAC>::rand_val());
    }
    return QVariant();
}

bool GenericListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << index.row();
    if(role == Qt::DisplayRole) {
        if(!index.isValid())
            return false;
        switch(type) {
            case 0: *(list<int>->begin() + index.row()) = Generator<int>::concrete_val(value.toString().toStdString()); break;
            case 1: *(list<double>->begin() + index.row()) = Generator<double>::concrete_val(value.toString().toStdString()); break;
            case 2: *(list<std::string>->begin() + index.row()) = Generator<std::string>::concrete_val(value.toString().toStdString()); break;
            case 3: *(list<IPv4>->begin() + index.row()) = Generator<IPv4>::concrete_val(value.toString().toStdString()); break;
            case 4: *(list<IPv6>->begin() + index.row()) = Generator<IPv6>::concrete_val(value.toString().toStdString()); break;
            case 5: *(list<MAC>->begin() + index.row()) = Generator<MAC>::concrete_val(value.toString().toStdString()); break;
        }
        return true;
    } else if(role == SortRole) {
        switch(type) {
            case 0: setSort<int>(value.toInt()); break;
            case 1: setSort<double>(value.toInt()); break;
            case 2: setSort<std::string>(value.toInt()); break;
            case 3: setSort<IPv4>(value.toInt()); break;
            case 4: setSort<IPv6>(value.toInt()); break;
            case 5: setSort<MAC>(value.toInt()); break;
        }
        return false;
    } else if(role == ListRole) {
        beginResetModel();
        switch(type) {
            case 0: setList<int>(value.toInt()); break;
            case 1: setList<double>(value.toInt()); break;
            case 2: setList<std::string>(value.toInt()); break;
            case 3: setList<IPv4>(value.toInt()); break;
            case 4: setList<IPv6>(value.toInt()); break;
            case 5: setList<MAC>(value.toInt()); break;
        }
        endResetModel();
        return true;
    }
    return false;
}

bool GenericListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    for(int i = 0; i < count; i++) switch(type) {
        case 0: list<int>->insert(list<int>->begin() + row + i, int()); break;
        case 1: list<double>->insert(list<double>->begin() + row + i, double()); break;
        case 2: list<std::string>->insert(list<std::string>->begin() + row + i, std::string()); break;
        case 3: list<IPv4>->insert(list<IPv4>->begin() + row + i, IPv4()); break;
        case 4: list<IPv6>->insert(list<IPv6>->begin() + row + i, IPv6()); break;
        case 5: list<MAC>->insert(list<MAC>->begin() + row + i, MAC()); break;
    }
    endInsertRows();
    return true;
}

bool GenericListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row == 0)
        return false;

    beginRemoveRows(parent, row, row + count - 1);
    for(int i = 0; i < count; i++) {
        switch(type) {
            case 0: list<int>->extract(list<int>->begin() + row - 1); break;
            case 1: list<double>->extract(list<double>->begin() + row - 1); break;
            case 2: list<std::string>->extract(list<std::string>->begin() + row - 1); break;
            case 3: list<IPv4>->extract(list<IPv4>->begin() + row - 1); break;
            case 4: list<IPv6>->extract(list<IPv6>->begin() + row - 1); break;
            case 5: list<MAC>->extract(list<MAC>->begin() + row - 1); break;
        }
    }
    endRemoveRows();
    return true;
}

void GenericListModel::setType(int i)
{
    switch(type) {
        case 0: delete list<int>; break;
        case 1: delete list<double>; break;
        case 2: delete list<std::string>; break;
        case 3: delete list<IPv4>; break;
        case 4: delete list<IPv6>; break;
        case 5: delete list<MAC>; break;
    }
    type = i;
    switch(type) {
        case 0: setList<int>(realisation); break;
        case 1: setList<double>(realisation); break;
        case 2: setList<std::string>(realisation); break;
        case 3: setList<IPv4>(realisation); break;
        case 4: setList<IPv6>(realisation); break;
        case 5: setList<MAC>(realisation); break;
    }
}

void GenericListModel::clear()
{
    beginResetModel();
    switch(type) {
        case 0: removeRows(1, list<int>->size()); break;
        case 1: removeRows(1, list<double>->size()); break;
        case 2: removeRows(1, list<std::string>->size()); break;
        case 3: removeRows(1, list<IPv4>->size()); break;
        case 4: removeRows(1, list<IPv6>->size()); break;
        case 5: removeRows(1, list<MAC>->size()); break;
    }
    endResetModel();
}

void GenericListModel::execSort()
{
    beginResetModel();
    switch(type) {
        case 0: list<int>->sort(); break;
        case 1: list<double>->sort(); break;
        case 2: list<std::string>->sort(); break;
        case 3: list<IPv4>->sort(); break;
        case 4: list<IPv6>->sort(); break;
        case 5: list<MAC>->sort(); break;
    }
    endResetModel();
}

template<typename T>
void GenericListModel::setSort(int i)
{
    switch (i) {
        case 0: list<T>->setSortAlgo(new QuickSort<T>); break;
        case 1: list<T>->setSortAlgo(new InsertionSort<T>); break;
        case 2: list<T>->setSortAlgo(new MergeSort<T>); break;
    }
}

template<typename T>
void GenericListModel::setList(int i)
{
    realisation = i;
    if(list<T>) delete list<T>;
    switch (realisation) {
        case 0: list<T> = new LinkedList<T>; break;
        case 1: list<T> = new ArrayList<T>; break;
        case 2: list<T> = new VectorList<T>; break;
    }
}
