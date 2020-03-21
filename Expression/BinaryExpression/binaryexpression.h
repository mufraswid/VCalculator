#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "../expression.h"

/*
 * Kelas BinaryExpression: kelas turunan Expression sebagia interface untuk memodelkan ekspresi biner. Kelas ini juga abstrak
 * seperti kelas Expression, dan memiliki turunan ekspresi biner yang disupport oleh kalkulator
*/

template<class T>
class BinaryExpression : public Expression<T> {
protected:
    Expression<T>* opr1;    //atribut operand kiri
    Expression<T>* opr2;    //atribut operand kanan
public:
    //Konstruktor
    BinaryExpression();

    //Konstruktor dengan parameter
    BinaryExpression(Expression<T>* x, Expression<T>* y){
        //set atribut dengan parameter konstruktor
        this->opr1 = x;
        this->opr2 = y;
    }

    //solve() : virtual untuk diimplementasikan sebagai evaluasi ekspresi biner oleh subclass-nya
    virtual T solve() = 0;
};

#endif // BINARYEXPRESSION_H
