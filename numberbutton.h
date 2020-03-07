#ifndef NUMBERBUTTON_H
#define NUMBERBUTTON_H

#include "button.h"

class NumberButton : public Button {
private:
    int inc;
public:
    NumberButton(int a);
    void onClick(TerminalExpression *a);
};

#endif // NUMBERBUTTON_H
