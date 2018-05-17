#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.create_map();
    w.create_thes();
    //w.SuggestionsList();
    w.setWindowTitle("CM^3 Dictionary");
    w.setStyleSheet("QMainWindow {background: ' light blue';}");
    w.show();

    return a.exec();
}
