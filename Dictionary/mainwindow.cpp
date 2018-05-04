#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include<QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include <QStyle>


void MainWindow::search_clicked(){

    ui->textEdit->clear();
    QString searchVal = ui->lineEdit->text();
    std::string str = searchVal.toStdString();
    std::string defn = search_map(str);
    QString find_defn = QString::fromStdString(defn);
    ui->textEdit->append(find_defn);

}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)
{
    //create_map();
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->pushButton->setText("Search");
    ui->lineEdit->setStyleSheet("border: grey");
    ui->textEdit->setStyleSheet("border: grey");
    connect (ui->pushButton, SIGNAL(clicked()),this,SLOT(search_clicked()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

