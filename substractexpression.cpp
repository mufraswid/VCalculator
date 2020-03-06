#include "substractexpression.h"
#include <iostream>
using namespace std;

SubstractExpression::SubstractExpression(Expression *x, Expression *y) : BinaryExpression(Expression *x, Expression *y){}

void SubstractExpression::solve(){
    return this->x - this->y;
}
