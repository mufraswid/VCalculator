#include "kalkulator.h"
#include "ui_kalkulator.h"
#include "master.h"

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
        connect(numButtons[i], SIGNAL(released()), this, SLOT(onClick()));
    }

    connect(ui->addbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->subbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->mulbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->divbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->rootbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->dotbutton, SIGNAL(released()), this, SLOT(onClick()));

    connect(ui->eqbutton, SIGNAL(released()), this, SLOT(onClickEq()));

    connect(ui->acbutton, SIGNAL(released()), this, SLOT(onClickAC()));
}

Kalkulator::~Kalkulator()
{
    delete ui;
}

void Kalkulator::onClick(){
    QPushButton *clicked = (QPushButton *)sender();
    QString value = clicked->text();
    QString disp = ui->display->textCursor().selectedText();
    input.setValue(input.solve()+value);
    ui->display->setText(input.solve());
}

void Kalkulator::onClickEq(){
    Parser parser(input.solve());
    Expression<double> *result;

    if(input.solve() == "") return; //no inputs

    try{
        parser.parseEquation();
    } catch(BaseException* e){
        ui->display->setText(QString::fromStdString(e->getErrMessage()));
        return;
    }

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

    ui->display->setText(QString::number(result->solve()));
    input.setValue("");
}

void Kalkulator::onClickAC(){
    input.setValue("");
    ui->display->setText(QString("0"));
}
