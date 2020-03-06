#ifndef ADDEXPRESSION_H
#define ADDEXPRESSION_H

#include "binaryexpression.h"

class AddExpression : public BinaryExpression{
    public:
        AddExpression(Expression *x, Expression *y);
        int solve();
};

#endif // ADDEXPRESSION_H
