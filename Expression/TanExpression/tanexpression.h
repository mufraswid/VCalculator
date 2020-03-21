#ifndef TANEXPRESSION_H
#define TANEXPRESSION_H

#include "../UnaryExpression/unaryexpression.h"

template<class T>
class TanExpression : public UnaryExpression<T>{
    public:
        TanExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        T solve(){
            return (T)tan(this->x->solve());
        }
};

#endif // TANEXPRESSION_H
