#ifndef PROXYMODEL_H
#define PROXYMODEL_H
#include <QSortFilterProxyModel>

class proxyModel : public QSortFilterProxyModel
{
private:
    QString _current;
    int columnId;
public:
    proxyModel(QObject *parent = nullptr);
    // QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void setCurrent(int columnId, const QString& value);
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};

#endif // PROXYMODEL_H
