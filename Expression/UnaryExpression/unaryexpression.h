#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "../expression.h"

/*
 * Kelas UnaryExpression: kelas turunan Expression sebagia interface untuk memodelkan ekspresi uner. Kelas ini juga abstrak
 * seperti kelas Expression, dan memiliki turunan ekspresi uner yang disupport oleh kalkulator
*/

template<class T>
class UnaryExpression : public Expression<T> {
protected:
    Expression<T>* x;   //atribut operand
public:
    //Konstruktor
    UnaryExpression(Expression<T>* x) {
        //set atribut dengan parameter konstruktor
        this->x = x;
    }

    //solve() : virtual untuk diimplementasikan sebagai evaluasi ekspresi uner oleh subclass-nya
    virtual T solve() = 0;
};

#endif // UNARYEXPRESSION_H
