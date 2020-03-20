#include "parser.h"

Parser::Parser(QString eq){
    this->equation = eq;
}

void Parser::parseEquation(){
    string eq = this->equation.toStdString();
    int whereOp;
    for(whereOp = 1; whereOp < eq.length(); whereOp++){
        if(eq[whereOp] == '+' || eq[whereOp] == '-' || eq[whereOp] == '*' || eq[whereOp] == '/'){
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

    this->leftSide = stod(left);
    this->rightSide = stod(right);
}

void Parser::scanOperand(string operand, int dext){
    if(operand[0] == '+' || operand[0] == '*' || operand[0] == '/'){
        InvalidOperatorUseException* e = new InvalidOperatorUseException(operand[0], 0, dext);
        throw e;
    }

    for(int i = 1; i < operand.length(); i++){
        if(operand[i] == '+' || operand[i] == '-' || operand[i] == '*' || operand[i] == '/'){
            InvalidOperatorUseException* e = new InvalidOperatorUseException(operand[i], i, dext);
            throw e;
        }
    }
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
