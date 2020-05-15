#ifndef LISTMODEL_H
#define LISTMODEL_H

#include "generator.h"

#include <QAbstractListModel>

enum Roles {
    RandomRole = Qt::UserRole + 1,
    SortRole,
    ListRole
};

class GenericListModel : public QAbstractListModel
{
    Q_OBJECT

    template <typename T> static BaseList<T>* list;
    static int type;
    static int realisation;

    template<typename T> void setSort(int i);
    template<typename T> void setList(int i);

public:
    explicit GenericListModel(QObject *parent = nullptr);
    
    ~GenericListModel();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

public slots:
    void setType(int i);

    void clear();
    
    void execSort();
};

#endif // LISTMODEL_H
