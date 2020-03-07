#include "divisionexpression.h"
#include <iostream>
using namespace std;

DivisionExpression::DivisionExpression(Expression *x, Expression *y) : BinaryExpression(x, y){}

int DivisionExpression::solve(){
    return x->solve() / y->solve();
}
