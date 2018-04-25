#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include<QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include <QtUiTools/QUiLoader>
#include <QVBoxLayout>


static QWidget *loadUi(QWidget *parent){
    QFile uifile(":/forms/mainwindow.ui");
    uifile.open(QIODevice::ReadOnly);

    QUiLoader loader;
    return loader.load(&uifile, parent);
}
static QString loadFile(){
    QFile inputFile(":/forms/entries.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    in.setCodec("UTF-8");
    return in.readAll();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget *myWindow = loadUi(this);
    ui_searchButton = findChild<QPushButton*>("Search");
    ui_searchBar = findChild<QLineEdit*>("lineEdit");
    ui_displayWin = findChild<QTextEdit*>("lineEdit");

    ui_displayWin->setText(loadFile());

    QVBoxLayout *layout = new QVBoxLayout;
    layout-> addWidget(myWindow);
    setLayout(layout);

    setWindowTitle(tr("Dictionary"));

}
