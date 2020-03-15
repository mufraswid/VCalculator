#ifndef MULTIPLYEXPRESSION_H
#define MULTIPLYEXPRESSION_H

#include "binaryexpression.h"

template<class T>
class MultiplyExpression : public BinaryExpression<T>{
    public:
        MultiplyExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        T solve(){
            return this->opr1->solve() * this->opr2->solve();
        }

};

#endif // MULTIPLYEXPRESSION_H
