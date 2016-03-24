#include "headers/tablemodel.h"
#include <QDebug>

void TableModel::setData(QList<QStringList> fileData)
{
    tableData = fileData;
}

void TableModel::setHeading(bool heading)
{
    isHeading = heading;
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    if(tableData.isEmpty())
        return 0;
    return isHeading?tableData.size()-1:tableData.size();
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

    if(index.row() >= (isHeading?tableData.size()-1:tableData.size()) || index.row() < 0)
        return QVariant();

    if(index.column() >= tableData.at(0).size() || index.column() < 0 )
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        QStringList row = tableData.at(isHeading?(index.row()+1):(index.row()));
        QString elem = row.at(index.column());
        return QVariant(elem);
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(tableData.isEmpty())
        return QVariant();

    if(section >= tableData.at(0).size() && orientation == Qt::Horizontal)
        return QVariant();

    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal && isHeading)
        {
            QStringList headerRow = tableData.at(0);
            return headerRow.at(section);
        }
        if(orientation == Qt::Vertical)
        {
            return section;
        }
    }
    return QVariant();
}
