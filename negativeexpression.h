#ifndef NEGATIVEEXPRESSION_H
#define NEGATIVEEXPRESSION_H

#include "unaryexpression.h"

template<class T>
class NegativeExpression : public UnaryExpression<T>{
    public:
        NegativeExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        T solve(){
            return (this->x->solve())*-1;
        }
};


#endif // NEGATIVEEXPRESSION_H
