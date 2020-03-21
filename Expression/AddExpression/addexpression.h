#ifndef ADDEXPRESSION_H
#define ADDEXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"

/*
 * Kelas AddExpression: kelas turunan BinaryExpression untuk memodelkan ekspresi biner penjumlahan
*/

template<class T>
class AddExpression : public BinaryExpression<T>{
    public:
        //Konstruktor : memanggil konstruktor superclass BinaryExpression untuk set operand kiri dan kanan
        AddExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        //solve : mengembalikan evaluasi penjumlahan operand kanan dan operand kiri
        T solve(){
            return this->opr1->solve() + this->opr2->solve();
        }

};

#endif // ADDEXPRESSION_H
