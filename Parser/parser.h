#ifndef PARSER_H
#define PARSER_H

#include "../Exception/nooperatorexception.h"
#include "../Exception/invalidoperatoruseexception.h"
#include "../Exception/dotoverloadexception.h"
#include "../Expression/terminalexpression.h"
#include <QString>
#include <bits/stdc++.h>
using namespace std;

class Parser {
private:
    QString equation;
    double leftSide;
    double rightSide;
    char oper;

public:
    Parser(QString eq);
    void parseEquation();
    void scanOperand(string operand, int dext);
    double getLeftSide();
    double getRightSide();
    char getOperator();
};

#endif // PARSER_H
