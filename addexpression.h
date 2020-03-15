#ifndef ADDEXPRESSION_H
#define ADDEXPRESSION_H

#include "binaryexpression.h"

template<class T>
class AddExpression : public BinaryExpression<T>{
    public:
        AddExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        T solve(){
            return this->opr1->solve() + this->opr2->solve();
        }

};

#endif // ADDEXPRESSION_H
