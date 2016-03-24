#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QList>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

private:
    QList<QStringList> tableData;

public:
    //TableModel(QObject* parent = Q_NULLPTR) = default;
    void setData(QList<QStringList> fileData);
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
};

#endif // TABLEMODEL_H
