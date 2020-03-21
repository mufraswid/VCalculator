#ifndef SINEXPRESSION_H
#define SINEXPRESSION_H

#include "../UnaryExpression/unaryexpression.h"

template<class T>
class SinExpression : public UnaryExpression<T>{
    public:
        SinExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        T solve(){
            return (T)sin(this->x->solve());
        }
};
#endif // SINEXPRESSION_H
