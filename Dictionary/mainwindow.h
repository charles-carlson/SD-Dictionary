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




class QLineEdit;
class QPushButton;
class QTextEdit;




namespace Ui{
class MainWindow;

}


class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    void create_map();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void search_clicked();

    std::string search_map(const std::string);
private:

    Ui::MainWindow *ui;

    std::map<std::string,std::string> map1;
};

#endif // MAINWINDOW_H
