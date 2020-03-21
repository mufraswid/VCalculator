#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "../expression.h"

/*
 * Kelas TerminalExpression: kelas turunan Expression yang merepresentasikan operand dari ekspresi
*/

template<class T>
class TerminalExpression : public Expression<T> {
protected:
    T val;      //atribut nilai operand
public:
    //Konstruktor
    TerminalExpression(){}

    //Konstruktor dengan parameter
    TerminalExpression(T x) {
        //set atribut dengan parameter
        this->val = x;
    }

    //solve() : mengembalikan nilai operand
    T solve() {
        return this->val;
    }

    //setValue() : mengubah nilai operand dengan nilai baru x
    void setValue(T x){
        this->val=x;
    }
};


#endif // TERMINALEXPRESSION_H
