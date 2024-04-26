#ifndef TABLEMODEL_H
#define TABLEMODEL_H
#include <QString>
#include <QList>
#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel
{
private:
    QList<QString> _header;
    QList<QList<QString>> _data;
public:
    TableModel(QString path, QObject* parent=nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QStringList getValues(int index) const;
};

#endif // TABLEMODEL_H
