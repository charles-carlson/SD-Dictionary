#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
class QLineEdit;
class QPushButton;
class QTextEdit;




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private slots:
    void search_clicked();
private:
    QPushButton *ui_searchButton;
    QTextEdit *ui_displayWin;
    QLineEdit *ui_searchBar;
};

#endif // MAINWINDOW_H
