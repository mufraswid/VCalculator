#include "mainwindow.h"
#include "terminalexpression.h"
#include "multiplyexpression.h"
#include "substractexpression.h"
#include "divisionexpression.h"
#include "addexpression.h"
#include "rootexpression.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>
using namespace std;

bool singleOperator = false;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->window->setText(QString::number(0.0));\
    QPushButton Button[10];
    for(int i = 0; i < 10; ++i){
        QString butName = "Button" + QString::number(i);
        Button[i] = Calc::findChild<QPushButton *>(butName);
        connect(Button[i], SIGNAL(released()), this,
                SLOT(onClick(i)));
    }
    connect(ui->eqbutton, SIGNAL(released()), this,
            SLOT(onClick("=")));
    connect(ui->plusbutton, SIGNAL(released()), this,
            SLOT(onClick("+")));
    connect(ui->minbutton, SIGNAL(released()), this,
            SLOT(onClick("-")));
    connect(ui->mulbutton, SIGNAL(released()), this,
            SLOT(onClick("*")));
    connect(ui->divbutton, SIGNAL(released()), this,
            SLOT(onClick("/")));
    connect(ui->rootbutton, SIGNAL(released()), this,
            SLOT(onClick()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onClick(int x){
    QPushButton* button = (QPushButton *)sender();
    QString value = button -> text();
    QString windowValue = ui -> window -> text();
    if(windowValue.toDouble()==0){
        ui -> window -> setText(QString::number(x));
    }
    else if (value==".")
    {
        QString val = windowValue + value;
        ui -> window -> setText(val);
    }
    else {
        QString val = value + windowValue;
        double v = val.toDouble();
        ui -> window -> setText(QString::number(v)); 
    }

}  
void MainWindow::onClick(string a){
    QPushButton* button = (QPushButton *)sender();
    QString value = button -> text();
    QString windowValue = ui -> window -> text();
    double v = windowValue.toDouble();
    if(!singleOperator){
        singleOperator=true;
        ui -> window -> setText(windowValue+value);
    }
    else{
        // parsing 
        string strval = windowValue.toStdString();
        int i;
        for (i=0; i<strval.size(); i++){
            if(strval[i]=='+'||strval[i]=='-'||strval[i]=='/'||strval[i]=='*'){
                i--;
                break;
            }
        }
        string a(strval,i);
        string b(strval.size()+i+2,strval.size()-i-2);
        QString ab(a), bc(b);
        double valA=ab.toDouble(), valB=bc.toDouble(), hasil=0;
        switch (strval[i+1])
        {
            case '+':
                AddExpression<double> c(new TerminalExpression<double>(valA), new TerminalExpression<double>(valB));
                hasil = c.solve();
                break;
            case '-':
                SubstractExpression<double> d(new TerminalExpression<double>(valA), new TerminalExpression<double>(valB));
                hasil = d.solve();
                break;
            case '/':
                DivisionExpression<double> e(new TerminalExpression<double>(valA), new TerminalExpression<double>(valB));
                hasil = e.solve();
                break;
            case '*':
                MultiplyExpression<double> f(new TerminalExpression<double>(valA), new TerminalExpression<double>(valB));
                hasil = f.solve();
                break;
            default:
                break;
        }
        if(a=="="){
            ui -> window -> setText(QString::number(hasil));
            singleOperator=false;
        }
        else{
            ui -> window -> setText(QString::number(hasil) + value);
        }
    }
}

void MainWindow::onClick(){
    QPushButton* button = (QPushButton *)sender();
    QString value = button -> text();
    QString windowValue = ui -> window -> text();
    double hasil=0, v = windowValue.toDouble();;
    RootExpression<double> c(new TerminalExpression<double>(v));
    hasil =c.solve();
    ui -> window -> setText(QString::number(hasil));
} 
