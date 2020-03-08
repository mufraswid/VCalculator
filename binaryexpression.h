#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "expression.h"

class BinaryExpression : public Expression {
protected:
    Expression* opr1;
    Expression* opr2;
public:
    BinaryExpression();
    BinaryExpression(Expression* x, Expression* y);
    void setOpr1(Expression* a);
    void setOpr2(Expression* a);
    virtual int solve() = 0;
};

#endif // BINARYEXPRESSION_H
