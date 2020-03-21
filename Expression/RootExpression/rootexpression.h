#ifndef ROOTEXPRESSION_H
#define ROOTEXPRESSION_H

#include "../UnaryExpression/unaryexpression.h"

/*
 * Kelas RootExpression: kelas turunan UnaryExpression untuk memodelkan ekspresi akar kuadrat dari operand
*/

template<class T>
class RootExpression : public UnaryExpression<T>{
    public:
        //Konstruktor : memanggil konstrktor superclass UnaryExpression untuk setting operand
        RootExpression(Expression<T> *x) : UnaryExpression<T>(x){}

        //solve : mengembalikan evaluasi akar kuadrat dari operand
        T solve(){
            return (T)sqrt(this->x->solve());
        }
};

#endif // ROOTEXPRESSION_H
