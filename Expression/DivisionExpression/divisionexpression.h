#ifndef DIVISIONEXPRESSION_H
#define DIVISIONEXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"

/*
 * Kelas DivisionExpression: kelas turunan BinaryExpression untuk memodelkan ekspresi biner pembagian
*/

template<class T>
class DivisionExpression : public BinaryExpression<T>{
    public:
        //Konstruktor : memanggil konstruktor superclass BinaryExpression untuk set operand kiri dan kanan
        DivisionExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        //solve : mengembalikan evaluasi pembagian operand kanan dan operand kiri
        T solve(){
            return this->opr1->solve() / this->opr2->solve();
        }

};

#endif // DIVISIONEXPRESSION_H
