#ifndef PARSER_H
#define PARSER_H

#include "../Exception/NoOperatorException/nooperatorexception.h"
#include "../Exception/InvalidOperatorUseException/invalidoperatoruseexception.h"
#include "../Exception/DotOverloadException/dotoverloadexception.h"
#include "../Exception/RootNegativeException/rootnegativeexception.h"
#include "../Exception/ZeroDivisionException/zerodivisionexception.h"
#include "../Expression/TerminalExpression/terminalexpression.h"
#include "../Exception/ZeroModException/zeromodexception.h"
#include "../Exception/DecimalModException/decimalmodexception.h"
#include "../Exception/DecExponentNegBaseException/decexponentnegbaseexception.h"
#include <QString>
#include <bits/stdc++.h>
using namespace std;

/*
 * Kelas Parser: adalah kelas untuk parsing input dari pengguna sebagai satu ekspresi yang bisa dievaluasikan
*/

class Parser {
private:
    string equation;   //atribut masukan input dari pengguna
    double leftSide;    //atribut operand kiri yang sudah di parse
    double rightSide;   //atribut operand kanan yang sudah di parse
    char oper;          //atribut operator dari ekspresi yang sudah di parse

public:
    //Konstruktor
    Parser(QString eq);

    //Konstruktor Overload
    Parser(string eq);

    //parseEquation() : parsing dari atribut equation untuk mengisi atribut operand kanan dan kiri serta operator
    void parseEquation();

    //scanOperand() : validasi setiap operand apakah dalam bentuk yang benar atau bukan. Bila tidak, maka akan dithrow error
    void scanOperand(string operand, int dext);

    //getter untuk operand kiri
    double getLeftSide();

    //getter untuk operand kanan
    double getRightSide();

    //getter untuk operator
    char getOperator();

    //converter dari string ke Double
    double strToDbl(string str);
};

#endif // PARSER_H
