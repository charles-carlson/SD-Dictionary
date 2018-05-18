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

    void create_map(); //creates map for dictionary
    void create_thes(); // creates map for thesaurus



    explicit MainWindow(QWidget *parent = 0); //creates window



    ~MainWindow();



private slots:

    void search_clicked(); //function that implements search functions once button is pressed
    void return_clicked();  //implements the search but goes back to prievious search
    std::string search_map(const std::string); //searches through map
    std::string search_multimap(std::string); // searches through map
    std::string search_thes(std::string); //searches through thesaurus


    std::string hamming_sug(const std::string);
    std::string hammingThes_sug(const std::string);

private:

    Ui::MainWindow *ui;

    std::vector <std::string> history; //vector of dictionary entries
    std::vector<std::string> history_thes; //vector of thesaurus entries
    std::multimap<std::string,std::string> map1; //map of dictonary

    std::multimap<std::string,std::string> thes; //map of thesaurus

    QStringList term;       //list of strings of all entries in dictionary
    QTextCursor scrollbar; //scrollbar object
    QStringList titleList; //list of all titles in dictionary





};

#endif // MAINWINDOW_H
