#ifndef COSEXPRESSION_H
#define COSEXPRESSION_H

#include "../UnaryExpression/unaryexpression.h"

/*
 * Kelas CosExpression: kelas turunan UnaryExpression untuk memodelkan ekspresi uner trigonometri cosinus
*/

template<class T>
class CosExpression : public UnaryExpression<T>{
    public:
        //Konstruktor : memanggil konstrktor superclass UnaryExpression untuk setting operand
        CosExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        //solve : mengembalikan evaluasi cosinus operand (operand dalam radian)
        T solve(){
            return (T)cos(this->x->solve());
        }
};
#endif // COSEXPRESSION_H
