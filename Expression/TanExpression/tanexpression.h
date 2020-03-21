#ifndef TANEXPRESSION_H
#define TANEXPRESSION_H

#include "../UnaryExpression/unaryexpression.h"

/*
 * Kelas TanExpression: kelas turunan UnaryExpression untuk memodelkan ekspresi uner trigonometri tangent
*/

template<class T>
class TanExpression : public UnaryExpression<T>{
    public:
        //Konstruktor : memanggil konstrktor superclass UnaryExpression untuk setting operand
        TanExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        //solve : mengembalikan evaluasi tangent operand (operand dalam radian)
        T solve(){
            return (T)tan(this->x->solve());
        }
};

#endif // TANEXPRESSION_H
