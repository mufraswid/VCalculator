#ifndef KALKULATOR_H
#define KALKULATOR_H

#include <QMainWindow>
#include "Expression/TerminalExpression/terminalexpression.h"
#include "Expression/AddExpression/addexpression.h"
#include "Expression/SubstractExpression/substractexpression.h"
#include "Expression/MultiplyExpression/multiplyexpression.h"
#include "Expression/DivisionExpression/divisionexpression.h"
#include "Expression/RootExpression/rootexpression.h"
#include "Expression/PowerExpression/powerexpression.h"
#include "Expression/ModExpression/modexpression.h"
#include "Expression/SinExpression/sinexpression.h"
#include "Expression/CosExpression/cosexpression.h"
#include "Expression/TanExpression/tanexpression.h"
#include "Exception/BaseException/baseexception.h"
#include "Parser/parser.h"

#include <bits/stdc++.h>
using namespace std;

namespace Ui {
class Kalkulator;
}

class Kalkulator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kalkulator(QWidget *parent = 0);
    ~Kalkulator();

private:
    Ui::Kalkulator *ui;
    double ans;
    TerminalExpression<QString> input;
    queue<double> memory;
    void setDisplay();

private slots:
    void onClick();
    void onClickEq();
    void onClickSqrt();
    void onClickAns();
    void onClickMod();
    void onClickSin();
    void onClickCos();
    void onClickTan();
    void onClickAC();
    void onClickDel();
    void onClickMC();
    void onClickMR();
};

#endif // KALKULATOR_H
