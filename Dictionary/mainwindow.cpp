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
    create_map();
    ui->setupUi(this);

    ui->pushButton->setIcon(QPixmap("/home/users/carlso13/Dictionary/Dictionary/m_glass2.png"));
    ui->pushButton->setIconSize(QSize(20,20));
    ui->textEdit->setReadOnly(true);
    ui->pushButton->setText("Search");
    //ui->pushButton->setStyleSheet("border: 1px solid;border-radius:10px; background-color: palette(base);");
    ui->lineEdit->setStyleSheet("border: 1px solid;border-radius:5px; background-color: palette(base);");
    ui->textEdit->setStyleSheet("border: 1px solid;border-radius:5px; background-color: palette(base);");
    ui->textEdit_2->setStyleSheet("border: 1px solid;border-radius:5px; background-color: palette(base);");
    connect (ui->pushButton, SIGNAL(clicked()),this,SLOT(search_clicked()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

