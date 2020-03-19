#ifndef ROOTEXPRESSION_H
#define ROOTEXPRESSION_H

#include "unaryexpression.h"

template<class T>
class RootExpression : public UnaryExpression<T>{
    public:
        RootExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        T solve(){
            return (T)sqrt(this->x->solve());
        }
};

#endif // ROOTEXPRESSION_H
