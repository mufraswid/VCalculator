#ifndef DIVISIONEXPRESSION_H
#define DIVISIONEXPRESSION_H

#include "binaryexpression.h"

class DivisionExpression : public BinaryExpression{
    public:
        DivisionExpression(Expression *x, Expression *y);
        int solve();
};
#endif // DIVISIONEXPRESSION_H
