#ifndef PARSER_H
#define PARSER_H

#include "../Exception/NoOperatorException/nooperatorexception.h"
#include "../Exception/InvalidOperatorUseException/invalidoperatoruseexception.h"
#include "../Exception/DotOverloadException/dotoverloadexception.h"
#include "../Exception/RootNegativeException/rootnegativeexception.h"
#include "../Expression/TerminalExpression/terminalexpression.h"
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
    double strToDbl(string str);
};

#endif // PARSER_H
