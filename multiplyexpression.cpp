#include "multiplyexpression.h"
#include <iostream>
using namespace std;

MultiplyExpression::MultiplyExpression(Expression *x, Expression *y) : BinaryExpression(x, y){}

int MultiplyExpression::solve(){
    return opr1->solve() * opr2->solve();
}
