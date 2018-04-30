#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Dictionary");
    w.setStyleSheet("QMainWindow {background: ' light blue';}");
    w.show();

    return a.exec();
}
