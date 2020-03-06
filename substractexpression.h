#ifndef SUBSTRACTEXPRESSION_H
#define SUBSTRACTEXPRESSION_H

#include "binaryexpression.h"

class SubstractExpression : public BinaryExpression{
    public:
        SubstractExpression(Expression *x, Expression *y);
        int solve();
};

#endif // SUBSTRACTEXPRESSION_H
