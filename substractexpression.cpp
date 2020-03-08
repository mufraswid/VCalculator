#include "substractexpression.h"
#include <iostream>
using namespace std;

SubstractExpression::SubstractExpression(Expression *x, Expression *y) : BinaryExpression(x, y){}

int SubstractExpression::solve(){
    return opr1->solve() - opr2->solve();
}
