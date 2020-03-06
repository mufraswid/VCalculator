#ifndef MULTIPLYEXPRESSION_H
#define MULTIPLYEXPRESSION_H

#include "binaryexpression.h"

class AddExpression : public BinaryExpression{
    public:
        AddExpression(Expression *x, Expression *y);
        int solve();
};

#endif // MULTIPLYEXPRESSION_H
