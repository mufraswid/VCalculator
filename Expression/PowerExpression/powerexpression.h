#ifndef POWEREXPRESSION_H
#define POWEREXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"
#include <bits/stdc++.h>
using namespace std;

/*
 * Kelas MultiplyExpression: kelas turunan BinaryExpression untuk memodelkan ekspresi biner perpangkatan
*/

template<class T>
class PowerExpression : public BinaryExpression<T>{
    public:
        //Konstruktor : memanggil konstruktor superclass BinaryExpression untuk set operand kiri dan kanan
        PowerExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        //solve : mengembalikan evaluasi operand kiri pangkat operand kanan
        T solve(){
            return (T)pow(this->opr1->solve(), this->opr2->solve());
        }

};

#endif // POWEREXPRESSION_H
