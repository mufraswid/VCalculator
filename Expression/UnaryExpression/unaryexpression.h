#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "../expression.h"

template<class T>
class UnaryExpression : public Expression<T> {
protected:
    Expression<T>* x;
public:
    UnaryExpression(Expression<T>* x) {
        this->x = x;
    }

    virtual T solve() = 0;
};

#endif // UNARYEXPRESSION_H
