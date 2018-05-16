#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include<fstream>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include <iostream>
#include <list>
#include <vector>
#include<QTextCursor>
#include <QLineEdit>
class QLineEdit;
class QPushButton;
class QTextEdit;




namespace Ui{
class MainWindow;

}


class MainWindow : public QMainWindow
{

    Q_OBJECT

    int maxSize = 0;
    int count = 1;

public:
    void create_map();

    void create_thes();

   // void SuggestionsList();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
   //void customEvent(QEvent * event);

private slots:
    void search_clicked();
    void return_clicked();
    std::string search_map(const std::string);
    std::string search_multimap(std::string);
    std::string search_thes(std::string);
    std::string hamming_sug(const std::string);
    //void lineEdit_change(QString);
private:
    //QLineEdit *lineEdit;
    Ui::MainWindow *ui;
    std::vector <std::string> history;
    std::multimap<std::string,std::string> map1;

    std::multimap<std::string,std::string> thes;

    QStringList term;
    QTextCursor scrollbar;
    QStringList titleList;


};

#endif // MAINWINDOW_H
