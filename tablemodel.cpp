#include "tablemodel.h"
#include <QFile>
#include <QMessageBox>
#include <QSet>

TableModel::TableModel(QString path, QObject* parent): QAbstractTableModel(parent) {
    QFile file(path);
    file.open(QFile::ReadOnly | QFile::Text);
    if (!(file.isOpen())) {
        QMessageBox error;
        error.setText("not found");
        error.exec();
    }
    else {
        QTextStream ss(&file);
        _header = ss.readLine().split(";");
        while (!(ss.atEnd())) {
            _data.append(ss.readLine().split(";"));
        }
    }
    file.close();
}

int TableModel::rowCount(const QModelIndex &parent) const {
    return _data.size();
};

int TableModel::columnCount(const QModelIndex &parent) const {
    return _header.size();
};

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (role==Qt::DisplayRole || role==Qt::EditRole)
        return _data[index.row()][index.column()];
    return QVariant();
};


QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role==Qt::DisplayRole) {
        if (orientation==Qt::Vertical) {
            return section + 1;
        } else {
            return _header[section];
        }
    }
    return QVariant();
}

QStringList TableModel::getValues(int index) const {
    QSet<QString> uniqueValues;
    for (const auto &row: _data) {
        if (!row[index].isEmpty()) {
            uniqueValues.insert(row[index]);
        }
    }
    QStringList res(uniqueValues.begin(), uniqueValues.end());
    return res;
}



