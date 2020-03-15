#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "expression.h"

template<class T>
class TerminalExpression : public Expression<T> {
protected:
    T val;
public:
    TerminalExpression(T x) {
        this->val = x;
    }

    T solve() {
        return this->val;
    }
};


#endif // TERMINALEXPRESSION_H
