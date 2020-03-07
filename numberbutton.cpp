#include "numberbutton.h"

NumberButton::NumberButton(int a){
    inc = a;
}

void NumberButton::onClick(TerminalExpression *a){
    a->setValue(a->solve()*10+inc);
}
