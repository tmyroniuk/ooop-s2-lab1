#ifndef LISTMODEL_H
#define LISTMODEL_H

#include "generator.h"

#include <QAbstractListModel>

enum Roles {
    RandomRole = Qt::UserRole + 1,
    SortRole,
    ListRole
};

template <typename T>
class ListModel : public QAbstractListModel
{
    Q_OBJECT

    BaseList<T>* list;

public:
    explicit ListModel(QObject *parent = nullptr);
    
    ~ListModel();

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

public slots:
    void clear();
    
    void sort();
};

#endif // LISTMODEL_H
