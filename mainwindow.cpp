#include "mainwindow.h"
#include "button.h"
#include "ui_mainwindow.h"

float a = 0;

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
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->label->setText(QString::number(a));
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->label->setText(QString::number(a));
}
