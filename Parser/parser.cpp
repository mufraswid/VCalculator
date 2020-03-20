#include "parser.h"

Parser::Parser(QString eq){
    this->equation = eq;
    this->oper = 'n';
}

double Parser::getLeftSide(){
    return this->leftSide;
}

double Parser::getRightSide(){
    return this->rightSide;
}

char Parser::getOperator(){
    return this->oper;
}

void Parser::parseEquation(){
    string eq = this->equation.toStdString();

    if(eq[0] == 'r'){
        this->oper = eq[0];
        scanOperand(eq.substr(1), 0);
        this->leftSide = strToDbl(eq.substr(1));
        return;
    }

    if(eq[0] == '+' || eq[0] == '*' || eq[0] == '/' || eq[0] == '.' || eq[0] == '^' || eq[0] == '%'){
        InvalidOperatorUseException* e = new InvalidOperatorUseException(eq[0], 0, 0);
        throw e;
    }

    int whereOp;
    for(whereOp = 1; whereOp < eq.length(); whereOp++){
        if(eq[whereOp] == '+' || eq[whereOp] == '-' || eq[whereOp] == '*' || eq[whereOp] == '/' || eq[whereOp] == '^' || eq[whereOp] == '%'){
            break;
        }
    }

    //throw NoOperatorException
    if(whereOp == eq.length()){
        NoOperatorException* e = new NoOperatorException();
        throw e;
    }

    this->oper = eq[whereOp];
    string left = eq.substr(0, whereOp);
    string right = eq.substr(whereOp+1);

    scanOperand(left, 0);
    scanOperand(right, 1);

    this->leftSide = strToDbl(left);
    this->rightSide = strToDbl(right);
}

void Parser::scanOperand(string operand, int dext){
    int nDot = 0;

    for(int i = 0; i < operand.length(); i++){
        if(operand[i] == '+' || operand[i] == '-' || operand[i] == '*' || operand[i] == '/' || operand[0] == 'r' || operand[0] == '^' || operand[0] == '%'){
            if(operand[i] != '-' || i != 0){
                InvalidOperatorUseException* e = new InvalidOperatorUseException(operand[i], i, dext);
                throw e;
            }
        }

        if(operand[i] == '.'){
            if(i == operand.length()-1){
                InvalidOperatorUseException* e = new InvalidOperatorUseException(operand[i], -1, dext);
                throw e;
            } else {
                nDot++;
            }
        }
    }

    if(nDot > 1){
        DotOverloadException* e = new DotOverloadException(nDot, dext);
        throw e;
    }

    if(this->oper == 'r' && operand[0] == '-'){
        RootNegativeException* e = new RootNegativeException();
        throw e;
    }
}

double Parser::strToDbl(string str){
    int dot;
    for(dot = 0; dot < str.length(); dot++){
        if(str[dot] == '.') break;
    }

    if(dot == str.length()){
        return stod(str);
    }

    double upper = stod(str.substr(0, dot));
    string lowerStr = str.substr(dot+1);
    double lower = stod(lowerStr) / pow(10, lowerStr.length());

    return upper+lower;
}
