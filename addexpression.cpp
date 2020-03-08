#include "addexpression.h"
#include <iostream>
using namespace std;

AddExpression::AddExpression(Expression *x, Expression *y) : BinaryExpression(x, y){}

int AddExpression::solve(){
    return opr1->solve() + opr2->solve();
}
