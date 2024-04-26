#include "mainwindow.h"
#include <iostream>
#include <QMessageBox>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qDebug()<< "hello world";
    w.show();
    return a.exec();
}
