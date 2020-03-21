#ifndef COSEXPRESSION_H
#define COSEXPRESSION_H

#include "../UnaryExpression/unaryexpression.h"

template<class T>
class CosExpression : public UnaryExpression<T>{
    public:
        CosExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        T solve(){
            return (T)cos(this->x->solve());
        }
};
#endif // COSEXPRESSION_H
