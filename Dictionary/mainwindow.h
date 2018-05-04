#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
//#include "EntryArrayP.h
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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void search_clicked();
    void displayEntry(int);
private:
    QString keyword;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
