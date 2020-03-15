#ifndef SUBSTRACTEXPRESSION_H
#define SUBSTRACTEXPRESSION_H

#include "binaryexpression.h"

template<class T>
class SubstractExpression : public BinaryExpression<T>{
    public:
        SubstractExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        T solve(){
            return this->opr1->solve() - this->opr2->solve();
        }

};

#endif // SUBSTRACTEXPRESSION_H
