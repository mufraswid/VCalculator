#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "expression.h"

class UnaryExpression : public Expression {
protected:
    Expression* x;
public:
    UnaryExpression(Expression* x);
    virtual int solve() = 0;
};

#endif // UNARYEXPRESSION_H
