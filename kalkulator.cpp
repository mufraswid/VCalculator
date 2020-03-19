#include "kalkulator.h"
#include "ui_kalkulator.h"
#include "Expression/terminalexpression.h"
#include "Expression/addexpression.h"
#include "Expression/substractexpression.h"
#include "Expression/multiplyexpression.h"
#include "Expression/divisionexpression.h"
#include "Parser/parser.h"

TerminalExpression<QString> input("");

Kalkulator::Kalkulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kalkulator)
{
    ui->setupUi(this);

    ui->display->setText("0");
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++){
        QString name = "button" + QString::number(i);
        numButtons[i] = Kalkulator::findChild<QPushButton *>(name);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(onClickNum()));
    }

    connect(ui->addbutton, SIGNAL(released()), this, SLOT(onClickOp()));
    connect(ui->subbutton, SIGNAL(released()), this, SLOT(onClickOp()));
    connect(ui->mulbutton, SIGNAL(released()), this, SLOT(onClickOp()));
    connect(ui->divbutton, SIGNAL(released()), this, SLOT(onClickOp()));
    connect(ui->rootbutton, SIGNAL(released()), this, SLOT(onClickOp()));
    connect(ui->dotbutton, SIGNAL(released()), this, SLOT(onClickOp()));

    connect(ui->eqbutton, SIGNAL(released()), this, SLOT(onClickEq()));
}

Kalkulator::~Kalkulator()
{
    delete ui;
}

void Kalkulator::onClickNum(){
    QPushButton *clicked = (QPushButton *)sender();
    QString value = clicked->text();
    QString disp = ui->display->text();
    input.setValue(input.solve()+value);
    ui->display->setText(input.solve());
}

void Kalkulator::onClickOp(){
    QPushButton *clicked = (QPushButton *)sender();
    QString value = clicked->text();
    input.setValue(input.solve()+value);
    ui->display->setText(input.solve());
}

void Kalkulator::onClickEq(){
    Parser parser(input.solve());
    Expression<double> *result;

    parser.parseEquation();
    TerminalExpression<double> leftSide(parser.getLeftSide());
    TerminalExpression<double> rightSide(parser.getRightSide());

    char oper = parser.getOperator();
    if(oper == '+'){
        result = new AddExpression<double>(&leftSide, &rightSide);
    } else if(oper == '-'){
        result = new SubstractExpression<double>(&leftSide, &rightSide);
    } else if(oper == '*'){
        result = new MultiplyExpression<double>(&leftSide, &rightSide);
    } else if(oper == '/'){
        result = new DivisionExpression<double>(&leftSide, &rightSide);
    }

    ui->display->setText();
    input.setValue("");
}