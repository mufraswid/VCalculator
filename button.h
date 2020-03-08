#ifndef BUTTON_H
#define BUTTON_H

#include "binaryexpression.h"
#include "bits/stdc++.h">

class Button {
public:
    Button();
    void onClick(Expression *a);
    void onClick(Expression *a, int b);
    void onClick(BinaryExpression *a, Expression *b);
};

#endif // BUTTON_H
