/*  /home/users/daly2/Dictionary/Dictionary/  */
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
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <iostream>



//std::string

void MainWindow::search_clicked(){

    ui->textEdit_2->clear();

    QString searchVal = ui->lineEdit->text();

    std::string str = searchVal.toStdString();

    std::string defn = search_multimap(str);
    std::string similar = search_multimap(str);
    QString find_str = QString::fromStdString(str);
    QString find_defn = QString::fromStdString(defn);

    history.push_back(str);
    maxSize++;

    ui->textEdit->append(find_str);
    ui->textEdit_2->append(find_defn);



}
void MainWindow::return_clicked(){


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
    std::string homedir;
    (homedir = getenv("HOME"));
    if ( homedir.length()== 0) {
        homedir = getpwuid(getuid())->pw_dir;
    }
    ui->setupUi(this);

    std::string m_glass=homedir+"/Dictionary/Dictionary/m_glass2.png";
    QString Qm_glass = QString::fromStdString(m_glass);
    ui->pushButton->setIcon(QPixmap(Qm_glass));// /home/users/daly2/Dictionary/Dictionary/
    ui->pushButton->setIconSize(QSize(20,20));


    std::string back_button=homedir+"/Dictionary/Dictionary/firefox_return.png";
    QString Qback_button = QString::fromStdString(back_button);
    ui->toolButton->setIcon(QPixmap(Qback_button));
    ui->toolButton->setIconSize(QSize(100,100));

    ui->textEdit->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);

    ui->pushButton->setText("Search");

    ui->lineEdit->setStyleSheet("border: 1px solid;"
                                "border-radius:5px;"
                                "background-color: palette(base);");
    ui->lineEdit->setPlaceholderText("Search...");
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

