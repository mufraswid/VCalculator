#include "terminalexpression.h"

TerminalExpression::TerminalExpression(int x) {
    this->x = x;
}

int TerminalExpression::solve() {
    return this->x;
}
