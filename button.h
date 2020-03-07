#ifndef BUTTON_H
#define BUTTON_H

#include "terminalexpression.h"

class Button {
public:
    Button();
    virtual void onClick(TerminalExpression *a) = 0;
};

#endif // BUTTON_H
