#include "mainwindow.h"
#include "button.h"
#include "ui_mainwindow.h"

int a = 0;
Button b;

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
    b.onClick(&a, 1);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_2_clicked()
{
    b.onClick(&a, 2);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_3_clicked()
{
    b.onClick(&a, 3);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_4_clicked()
{
    b.onClick(&a, 4);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_5_clicked()
{
    b.onClick(&a, 5);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_6_clicked()
{
    b.onClick(&a, 6);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_7_clicked()
{
    b.onClick(&a, 7);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_8_clicked()
{
    b.onClick(&a, 8);
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_9_clicked()
{
    b.onClick(&a, 9);
    ui->label->setText(QString::number(a));
}
