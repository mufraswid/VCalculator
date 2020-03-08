#ifndef ROOTEXPRESSION_H
#define ROOTEXPRESSION_H

#include "unaryexpression.h"

class RootExpression : public UnaryExpression{
    public:
        RootExpression(Expression *x);
        int solve();
};

#endif // ROOTEXPRESSION_H
