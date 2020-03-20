#ifndef POWEREXPRESSION_H
#define POWEREXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"
#include <bits/stdc++.h>
using namespace std;

template<class T>
class PowerExpression : public BinaryExpression<T>{
    public:
        PowerExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        T solve(){
            return (T)pow(this->opr1->solve(), this->opr2->solve());
        }

};

#endif // POWEREXPRESSION_H
