#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>
using namespace std;

int a = 0;

void add(int *a, int val){
	*a += val;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    add(&a, 1);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_2_clicked()
{
    add(&a, 2);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_3_clicked()
{
    add(&a, 3);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_4_clicked()
{
    add(&a, 4);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_5_clicked()
{
    add(&a, 5);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_6_clicked()
{
    add(&a, 6);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_7_clicked()
{
    add(&a, 7);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_8_clicked()
{
   add(&a, 8);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_9_clicked()
{
    add(&a, 9);
    ui->label->setText(QString::number(a));
}
