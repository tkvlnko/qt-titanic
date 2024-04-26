#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include "proxymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    TableModel *tmodel;
    proxyModel *proxy;
};
#endif // MAINWINDOW_H
