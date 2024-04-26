#include "proxymodel.h"

proxyModel::proxyModel(QObject *parent) : QSortFilterProxyModel(parent), _current("1") {}


bool proxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    QModelIndex currentIndex = sourceModel()->index(sourceRow, columnId, sourceParent);
    if(sourceModel()->data(currentIndex) != _current && !(_current.isEmpty())) {
        return false;
    }
    return true;
};

// QVariant headerData(int section, Qt::Orientation orientation, int role) const {
//     return sourceModel()->headerData(section, orientation, role);
// }


void proxyModel::setCurrent(int columnId, const QString& value) {
    _current = value;
    this->columnId = columnId;
    // if (value != _current) {
    //     _current = value;
    // }
    invalidateFilter();
}
