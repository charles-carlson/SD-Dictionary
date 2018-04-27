#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include<QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include <QtUiTools/QUiLoader>
#include <QVBoxLayout>
#include <QIODevice>

void MainWindow::search_clicked(){

    ui->textBrowser->append(keyword);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Search");
    keyword = ui->lineEdit->text();
    connect (ui->pushButton, SIGNAL(clicked()),this,SLOT(search_clicked()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
