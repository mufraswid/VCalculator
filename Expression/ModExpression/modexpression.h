#ifndef MODEXPRESSION_H
#define MODEXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"

template<class T>
class ModExpression : public BinaryExpression<T>{
    public:
        ModExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        T solve(){
            return (int)this->opr1->solve() % (int)this->opr2->solve();
        }

};
#endif // MODEXPRESSION_H
