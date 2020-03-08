#include "mainwindow.h"
#include "button.h"
#include "terminalexpression.h"
#include "ui_mainwindow.h"

TerminalExpression a(0);
Button* button;
BinaryExpression* result;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_button1_clicked() {

}

void MainWindow::on_button2_clicked() {

}

void MainWindow::on_button3_clicked() {

}

void MainWindow::on_button4_clicked() {

}

void MainWindow::on_button5_clicked() {

}

void MainWindow::on_button6_clicked() {

}

void MainWindow::on_button7_clicked() {

}

void MainWindow::on_button8_clicked() {

}

void MainWindow::on_button9_clicked() {

}
