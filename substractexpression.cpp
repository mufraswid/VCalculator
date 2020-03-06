#include "substractexpression.h"
#include <iostream>
using namespace std;

SubstractExpression::SubstractExpression(Expression *x, Expression *y) : BinaryExpression(x, y){}

int SubstractExpression::solve(){
    return this->x - this->y;
}
