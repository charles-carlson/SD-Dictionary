/*  /home/users/carlso13/Dictionary/Dictionary/  */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include <iostream>
#include<algorithm>
#include <QString>
#include <QFile>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include <QStyle>
#include <QAbstractButton>
#include <vector>
#include <QCompleter>
#include <QEvent>
#include <QDebug>
#include <QListView>
/*class CompleteEvent : public QEvent{
public:
    CompleteEvent(QLineEdit *lineEdit) : QEvent(QEvent::User),m_lineEdit(lineEdit){ }

    void complete(){
        m_lineEdit->completer()->complete();
    }
 private:
    QLineEdit *m_lineEdit;
};*/

void MainWindow::search_clicked(){
    int counter=0;

    ui->textBrowser_2->clear();

    QString searchVal = ui->lineEdit->text();
    std::string str = searchVal.toStdString();
    std::string defn = search_multimap(str);
    QString find_str = QString::fromStdString(str);
    term << find_str;
    QString find_defn = QString::fromStdString(defn);

    history.push_back(str);
    maxSize++;

    for(int i=0;i<term.length();i++){
        if(term[i]==(find_str))
            counter++;
    }

    if(counter < 2)
        ui->textBrowser->append(find_str);
    ui->textBrowser_2->append(find_defn);
    ui->textBrowser_2->textCursor();
    scrollbar.setPosition(0);
    ui->textBrowser_2->setTextCursor(scrollbar);




}
void MainWindow::return_clicked(){


    ui->textBrowser_2->clear();

    std::string str = history[(maxSize-1) - count];
    count++;
    std::string defn = search_multimap(str);

    QString find_defn = QString::fromStdString(defn);
    QString find_str = QString::fromStdString(str);


    ui->textBrowser_2->append(find_defn);
    scrollbar.setPosition(0);
    ui->textBrowser_2->setTextCursor(scrollbar);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    std::ifstream g("/home/users/carlso13/Dictionary/Dictionary/dict.txt");
    if(!g){
        std::cerr << "Not found"<<endl;
    }
    std::string title, def;
    QString newtitle;
    while(g.good())
      {
        getline(g,title, '#');

        getline(g,def,'#');

        titleList.append(QString::fromStdString(title));

      }
    g.close();

    QCompleter *autocomplete = new QCompleter(titleList,this);
    autocomplete->setCaseSensitivity(Qt::CaseInsensitive);
    autocomplete->setModelSorting(QCompleter::CaseSensitivelySortedModel);
    autocomplete->setCompletionMode(QCompleter::UnfilteredPopupCompletion);

    ui->lineEdit->setCompleter(autocomplete);

    ui->pushButton->setIcon(QPixmap("/home/users/carlso13/Dictionary/Dictionary/m_glass2.png"));
    ui->pushButton->setIconSize(QSize(20,20));

    ui->toolButton->setIcon(QPixmap("/home/users/carlso13/Dictionary/Dictionary/firefox_return.png"));
    ui->toolButton->setIconSize(QSize(100,100));



    ui->pushButton->setText("Search");


    ui->lineEdit->setStyleSheet("border: 1px solid;"
                                "border-radius:5px;"
                                "background-color: palette(base);");
    ui->lineEdit->setPlaceholderText("Search...");

    ui->textBrowser->setStyleSheet("border: 1px solid;"
                                "border-radius:5px;"
                                "background-color: palette(base);");
    ui->textBrowser_2->setStyleSheet("border: 1px solid;"
                                  "border-radius:5px;"
                                  "background-color: palette(base);");

    //connect(lineEdit, SIGNAL(textChanged(QString)), SLOT(lineEdit_change(QString)));
    connect (ui->pushButton, SIGNAL(clicked()),this,SLOT(search_clicked()));
    connect (ui->toolButton, SIGNAL(clicked()),this,SLOT(return_clicked()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));

}
/*void MainWindow::customEvent(QEvent *event){

    QMainWindow::customEvent(event);
    if(event->type()==QEvent::User)
        ((CompleteEvent *)event)->complete();
}
void MainWindow::lineEdit_change(QString keyword){

    if(keyword.length()==0)
        QApplication::postEvent(this, new CompleteEvent((QLineEdit *)sender()));


}*/

MainWindow::~MainWindow()
{
    delete ui;
}

