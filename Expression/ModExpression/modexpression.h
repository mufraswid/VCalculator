#ifndef MODEXPRESSION_H
#define MODEXPRESSION_H

#include "../BinaryExpression/binaryexpression.h"

/*
 * Kelas ModExpression: kelas turunan BinaryExpression untuk memodelkan ekspresi biner modulo
*/

template<class T>
class ModExpression : public BinaryExpression<T>{
    public:
        //Konstruktor : memanggil konstruktor superclass BinaryExpression untuk set operand kiri dan kanan
        ModExpression(Expression<T> *x, Expression<T> *y) : BinaryExpression<T>(x, y){}

        //solve : mengembalikan evaluasi operand kiri modulo operand kanan
        T solve(){
            return (int)this->opr1->solve() % (int)this->opr2->solve();
        }

};
#endif // MODEXPRESSION_H
