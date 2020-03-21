#ifndef SINEXPRESSION_H
#define SINEXPRESSION_H

#include "../UnaryExpression/unaryexpression.h"

/*
 * Kelas SinExpression: kelas turunan UnaryExpression untuk memodelkan ekspresi uner trigonometri sinus
*/

template<class T>
class SinExpression : public UnaryExpression<T>{
    public:
        //Konstruktor : memanggil konstrktor superclass UnaryExpression untuk setting operand
        SinExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        //solve : mengembalikan evaluasi sinus operand (operand dalam radian)
        T solve(){
            return (T)sin(this->x->solve());
        }
};
#endif // SINEXPRESSION_H
