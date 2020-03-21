#ifndef MULTIPLYEXPRESSION_H
#define MULTIPLYEXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"

/*
 * Kelas MultiplyExpression: kelas turunan BinaryExpression untuk memodelkan ekspresi biner perkalian
*/

template<class T>
class MultiplyExpression : public BinaryExpression<T>{
    public:
        //Konstruktor : memanggil konstruktor superclass BinaryExpression untuk set operand kiri dan kanan
        MultiplyExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        //solve : mengembalikan evaluasi perkalian operand kiri dan operand kanan
        T solve(){
            return this->opr1->solve() * this->opr2->solve();
        }

};

#endif // MULTIPLYEXPRESSION_H
