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

/*
 * Kelas Kalkulator: adalah kelas dari aplikasi kalkulator yang dibuat
*/

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
    Ui::Kalkulator *ui;                     //ui window dari GUI
    double ans;                             //atribut ans : menyimpan jawaban terakhir yang digenerate oleh kalkulator
    TerminalExpression<QString> input;      //atribut input : menyimpan string input dari pengguna untuk selanjutnya di parse
    queue<double> memory;                   //atribut memory : menyimpan jawaban yang diinginkan pengguna ke kalkulator
    void setDisplay();                      //prosedur untuk menampilkan equation yang diketik pengguna ke layar
    void setDisplay(QString a);             //prosedur untuk menampilkan equation yang diketik pengguna ke layar (OVERLOAD)

private slots:
    void onClick();                         //method onClick button digit
    void onClickEq();                       //method onClick button sama dengan (=)
    void onClickSqrt();                     //method onClick button sqrt (root)
    void onClickAns();                      //method onClick button ans
    void onClickMod();                      //method onClick button mod
    void onClickSin();                      //method onClick button sin
    void onClickCos();                      //method onClick button cos
    void onClickTan();                      //method onClick button tan
    void onClickAC();                       //method onClick button AC (clear)
    void onClickDel();                      //method onClick button del
    void onClickMC();                       //method onClick button MC (masukkan ke memory)
    void onClickMR();                       //method onClick button MR (invoke memory)
};

#endif // KALKULATOR_H
