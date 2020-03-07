#include "terminalexpression.h"

TerminalExpression::TerminalExpression(int x) {
    this->val = x;
}

int TerminalExpression::solve() {
    return this->val;
}

void TerminalExpression::setValue(int a){
    this->val = a;
}
