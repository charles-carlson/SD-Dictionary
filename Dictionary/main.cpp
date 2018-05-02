#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(Dictionary);

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("CM^3 Dictionary");
    w.setStyleSheet("QMainWindow {background: ' light blue';}");
    w.show();

    return a.exec();
}
