/*  /home/users/carlso13/Dictionary/Dictionary/  */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include <QStyle>
#include <QAbstractButton>
#include <vector>

void MainWindow::search_clicked(){

    ui->textEdit_2->clear();
    ui->textEdit->clear();
    QString searchVal = ui->lineEdit->text();

    std::string str = searchVal.toStdString();

    std::string defn = search_multimap(str);
    QString find_str = QString::fromStdString(str);
    QString find_defn = QString::fromStdString(defn);

    history.push_back(str);
    maxSize++;

    ui->textEdit->append(find_str);
    ui->textEdit_2->append(find_defn);



}
void MainWindow::return_clicked(){

    ui->textEdit->clear();
    ui->textEdit_2->clear();

    std::string str = history[(maxSize-1) - count];
    count++;
    std::string defn = search_multimap(str);

    QString find_defn = QString::fromStdString(defn);
    QString find_str = QString::fromStdString(str);

    ui->textEdit->append(find_str);
    ui->textEdit_2->append(find_defn);


}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->pushButton->setIcon(QPixmap("/home/users/carlso13/Dictionary/Dictionary/m_glass2.png"));
    ui->pushButton->setIconSize(QSize(20,20));

    ui->toolButton->setIcon(QPixmap("/home/users/carlso13/Dictionary/Dictionary/firefox_return.png"));
    ui->toolButton->setIconSize(QSize(100,100));

    ui->textEdit->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);

    ui->pushButton->setText("Search");

    ui->lineEdit->setStyleSheet("border: 1px solid;"
                                "border-radius:5px;"
                                "background-color: palette(base);");
    ui->textEdit->setStyleSheet("border: 1px solid;"
                                "border-radius:5px;"
                                "background-color: palette(base);");
    ui->textEdit_2->setStyleSheet("border: 1px solid;"
                                  "border-radius:5px;"
                                  "background-color: palette(base);");

    connect (ui->pushButton, SIGNAL(clicked()),this,SLOT(search_clicked()));
    connect (ui->toolButton, SIGNAL(clicked()),this,SLOT(return_clicked()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));

}
MainWindow::~MainWindow()
{
    delete ui;
}

