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
#include "EntryArrayP.h"

void MainWindow::search_clicked(){
    ui->textEdit->clear();
    QString searchVal = ui->lineEdit->text();
    ui->textEdit->append(searchVal);

    displayEntry(search(searchVal));
}
void MainWindow::displayEntry(int index){
//  QString filename = "Entry.txt";
//  QFile file(filename);
  //file.open(QFIle::ReadOnly | QFile::Text);
 // QTextStream ReadFile(&file);






}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Search");
    ui->lineEdit->setStyleSheet("border: grey");
    ui->textEdit->setStyleSheet("border: grey");
    keyword = ui->lineEdit->text();
    connect (ui->pushButton, SIGNAL(clicked()),this,SLOT(search_clicked()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
