#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "expression.h"


class TerminalExpression : public Expression {
protected:
    int val;
public:
    TerminalExpression(int x);
    int solve();
    void setValue(int a);
};


#endif // TERMINALEXPRESSION_H
