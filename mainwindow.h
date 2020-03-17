#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bits/stdc++.h>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onClick(int); //kalo button angka yang dipencet 
    void onClick(string); // kalo button operasi yang dipencet kecuali root sama negative
    void onClick(); // kalo button root sama negative dipencet

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
