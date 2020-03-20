#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "../expression.h"

template<class T>
class BinaryExpression : public Expression<T> {
protected:
    Expression<T>* opr1;
    Expression<T>* opr2;
public:
    BinaryExpression();
    BinaryExpression(Expression<T>* x, Expression<T>* y){
        this->opr1 = x;
        this->opr2 = y;
    }

    virtual T solve() = 0;
};

#endif // BINARYEXPRESSION_H
