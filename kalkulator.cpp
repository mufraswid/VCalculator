#include "kalkulator.h"
#include "ui_kalkulator.h"

Kalkulator::Kalkulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kalkulator)
{
    ui->setupUi(this);

    input.setValue("");
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
    connect(ui->rootbutton, SIGNAL(released()), this, SLOT(onClickSqrt()));
    connect(ui->powbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->dotbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->modbutton, SIGNAL(released()), this, SLOT(onClickMod()));
    connect(ui->ansbutton, SIGNAL(released()), this, SLOT(onClickAns()));
    connect(ui->sinbutton, SIGNAL(released()), this, SLOT(onClickSin()));
    connect(ui->cosbutton, SIGNAL(released()), this, SLOT(onClickCos()));
    connect(ui->tanbutton, SIGNAL(released()), this, SLOT(onClickTan()));

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
    input.setValue(input.solve()+value);
    setDisplay();
}

void Kalkulator::onClickSqrt(){
    input.setValue(input.solve()+QString("r"));
    setDisplay();
}

void Kalkulator::onClickAns(){
    input.setValue(input.solve()+QString::number(ans));
    setDisplay();
}

void Kalkulator::onClickMod(){
    input.setValue(input.solve()+QString("%"));
    setDisplay();
}

void Kalkulator::onClickSin(){
    input.setValue(input.solve()+QString("s"));
    setDisplay();
}

void Kalkulator::onClickCos(){
    input.setValue(input.solve()+QString("c"));
    setDisplay();
}

void Kalkulator::onClickTan(){
    input.setValue(input.solve()+QString("t"));
    setDisplay();
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
    } else if(oper == 'r'){
        result = new RootExpression<double>(&leftSide);
    } else if(oper == '^'){
        result = new PowerExpression<double>(&leftSide, &rightSide);
    } else if(oper == '%'){
        result = new ModExpression<double>(&leftSide, &rightSide);
    } else if(oper == 's'){
        result = new SinExpression<double>(&leftSide);
    } else if(oper == 'c'){
        result = new CosExpression<double>(&leftSide);
    } else if(oper == 't'){
        result = new TanExpression<double>(&leftSide);
    }

    ans = result->solve();
    ui->display->setText(QString::number(ans));
    input.setValue("");
}

void Kalkulator::onClickAC(){
    input.setValue("");
    ui->display->setText(QString("0"));
    for(int i = 0; i < memory.size(); i++){
        memory.pop();
    }
}

void Kalkulator::onClickDel(){
    string str = input.solve().toStdString();
    if(str.length() <= 1){
        input.setValue("");
        ui->display->setText(QString("0"));
    } else {
        str = str.substr(0, str.length()-1);
        input.setValue(QString::fromStdString(str));
        setDisplay();
    }
}

void Kalkulator::onClickMC(){
    memory.push(ans);
}

void Kalkulator::onClickMR(){
    if(!memory.empty()){
        input.setValue(input.solve()+QString::number(memory.front()));
        setDisplay();
        memory.pop();
    }
}

void Kalkulator::setDisplay(){
   string temp = "";
   string process = input.solve().toStdString();
   for(int i = 0; i < process.length(); i++){
       if(process[i] == 'r'){
           temp += "sqrt";
       } else if(process[i] == '%'){
           temp += "mod";
       } else if(process[i] == 's'){
           temp += "sin";
       } else if(process[i] == 'c'){
           temp += "cos";
       } else if(process[i] == 't'){
           temp += "tan";
       } else {
           temp += process[i];
       }
   }

   ui->display->setText(QString::fromStdString(temp));
}
