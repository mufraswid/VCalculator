#include "binaryexpression.h"

BinaryExpression::BinaryExpression(Expression* x, Expression* y) {
    this->opr1 = x;
    this->opr2 = y;
}

void BinaryExpression::setOpr1(Expression *a){
    this->opr1 = a;
}

void BinaryExpression::setOpr2(Expression* a){
    this->opr2 = a;
}
