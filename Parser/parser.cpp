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

    if(whereOp == eq.length()){
        //throw 'tidak ada operand!'
    }

    this->oper = eq[whereOp];
    string left = eq.substr(0, whereOp+1);
    string right = eq.substr(whereOp);

    scanOperand(left, 0);
    scanOperand(right, 1);

    this->leftSide = stod(left);
    this->rightSide = stod(right);
}

void Parser::scanOperand(string operand, int dext){
    if(operand[0] == '+'){
        //throw 'gaperlu tambah didepan!'
    } else if(operand[0] == '*' || operand[0] == '/'){
        //throw 'illegal operator di depan operand'
    }

    for(int i = 1; i < operand.length(); i++){
        if(operand[i] == '+' || operand[i] == '-' || operand[i] == '*' || operand[i] == '/'){
            //throw 'di oper ke dext, digit ke i, ada operator nich'
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
