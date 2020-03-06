#ifndef TERMINALEXPRESSION_H
#define TERMINALEXPRESSION_H

#include "expression.h"


class TerminalExpression : public Expression {
protected:
    int x;
public:
    TerminalExpression(int x);
    int solve();
};


#endif // TERMINALEXPRESSION_H
