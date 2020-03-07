#include "mainwindow.h"
#include "numberbutton.h"
#include "terminalexpression.h"
#include "ui_mainwindow.h"

TerminalExpression a(0);

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
    NumberButton button(1);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}

void MainWindow::on_pushButton_2_clicked()
{
    NumberButton button(2);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}

void MainWindow::on_pushButton_3_clicked()
{
    NumberButton button(3);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}

void MainWindow::on_pushButton_4_clicked()
{
    NumberButton button(4);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}

void MainWindow::on_pushButton_5_clicked()
{
    NumberButton button(5);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}

void MainWindow::on_pushButton_6_clicked()
{
    NumberButton button(6);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}

void MainWindow::on_pushButton_7_clicked()
{
    NumberButton button(7);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}

void MainWindow::on_pushButton_8_clicked()
{
    NumberButton button(8);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}

void MainWindow::on_pushButton_9_clicked()
{
    NumberButton button(9);
    button.onClick(&a);
    ui->label->setText(QString::number(a.solve()));
}
