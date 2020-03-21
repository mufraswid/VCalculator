#ifndef SUBSTRACTEXPRESSION_H
#define SUBSTRACTEXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"

/*
 * Kelas SubstractExpression: kelas turunan BinaryExpression untuk memodelkan ekspresi biner pengurangan
*/


template<class T>
class SubstractExpression : public BinaryExpression<T>{
    public:
        //Konstruktor : memanggil konstruktor superclass BinaryExpression untuk set operand kiri dan kanan
        SubstractExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        //solve : mengembalikan evaluasi pengurangan operand kanan dan operand kiri
        T solve(){
            return this->opr1->solve() - this->opr2->solve();
        }

};

#endif // SUBSTRACTEXPRESSION_H
