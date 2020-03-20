#ifndef DIVISIONEXPRESSION_H
#define DIVISIONEXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"

template<class T>
class DivisionExpression : public BinaryExpression<T>{
    public:
        DivisionExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        T solve(){
            return this->opr1->solve() / this->opr2->solve();
        }

};

#endif // DIVISIONEXPRESSION_H
