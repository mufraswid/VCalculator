#include "kalkulator.h"
#include "ui_kalkulator.h"
#include "master.h"

TerminalExpression<QString> input("");
double ans;
queue<double> memory;

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
    connect(ui->powbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->dotbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->ansbutton, SIGNAL(released()), this, SLOT(onClick()));

    connect(ui->eqbutton, SIGNAL(released()), this, SLOT(onClickEq()));
    connect(ui->acbutton, SIGNAL(released()), this, SLOT(onClickAC()));
    connect(ui->delbutton, SIGNAL(released()), this, SLOT(onClickDel()));
    connect(ui->mcbutton, SIGNAL(released()), this, SLOT(onClickMC()));
    connect(ui->mrbutton, SIGNAL(released()), this, SLOT(onClickMR()));
}

Kalkulator::~Kalkulator()
{
    delete ui;
}

void Kalkulator::onClick(){
    QPushButton *clicked = (QPushButton *)sender();
    QString value = clicked->text();
    if(value == "root"){
        input.setValue(input.solve()+QString("r"));
    } else if(value == "ans"){
        input.setValue(input.solve()+QString::number(ans));
    } else {
        input.setValue(input.solve()+value);
    }
    ui->display->setText(input.solve());
}

void Kalkulator::onClickEq(){
    Parser parser(input.solve());
    Expression<double> *result;

    if(input.solve() == "") return; //no inputs

    try{
        parser.parseEquation();
    } catch(BaseException* e){
        ui->errordisplay->setText(QString::fromStdString(e->getErrMessage()));
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
    } else if(oper == 'r'){
        result = new RootExpression<double>(&leftSide);
    } else if(oper == '^'){
        result = new PowerExpression<double>(&leftSide, &rightSide);
    }

    ans = result->solve();
    ui->display->setText(QString::number(ans));
    input.setValue("");
}

void Kalkulator::onClickAC(){
    input.setValue("");
    ui->display->setText(QString("0"));
    ui->errordisplay->setText(QString(""));
}

void Kalkulator::onClickDel(){
    string str = input.solve().toStdString();
    if(str.length() <= 1){
        input.setValue("");
        ui->display->setText(QString("0"));
    } else {
        str = str.substr(0, str.length()-1);
        input.setValue(QString::fromStdString(str));
        ui->display->setText(input.solve());
    }
}

void Kalkulator::onClickMC(){
    memory.push(ans);
}

void Kalkulator::onClickMR(){
    if(!memory.empty()){
        input.setValue(input.solve()+QString::number(memory.front()));
        ui->display->setText(input.solve());
        memory.pop();
    }
}
