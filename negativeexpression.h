#ifndef NEGATIVEEXPRESSION_H
#define NEGATIVEEXPRESSION_H

#include "unaryexpression.h"

class NegativeExpression : public UnaryExpression{
    public:
        NegativeExpression(Expression *x);
        int solve();
};


#endif // NEGATIVEEXPRESSION_H
