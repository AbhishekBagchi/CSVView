#include "tablemodel.h"

void TableModel::setData(QList<QStringList> fileData)
{
    tableData = fileData;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if(tableData.isEmpty())
        return 0;
    return tableData.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if(tableData.isEmpty() || tableData.at(0).isEmpty())
        return 0;

    return tableData.at(0).size();
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    if(tableData.isEmpty())
        return QVariant();

    if(index.row() >= tableData.size() || index.row() < 0)
        return QVariant();

    if(index.column() >= tableData.at(0).size() || index.column() < 0 )
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        QStringList row = tableData.at(index.row());
        QString elem = row.at(index.column());
        return QVariant(elem);
    }

    return QVariant();
}
