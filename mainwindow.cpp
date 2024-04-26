#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include "proxymodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), tmodel(new TableModel("/Users/apple/Desktop/titanic-survival-rate-232/data/titanic.csv")),
    proxy(new proxyModel)
{
    ui->setupUi(this);
    proxy->setSourceModel(tmodel);
    ui->tableView->setModel(proxy);
    ui->comboBox->addItems(tmodel->getValues(2));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tmodel;
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    proxy->setCurrent(2, arg1);
}

