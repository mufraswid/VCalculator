#include "addexpression.h"
#include <iostream>
using namespace std;

AddExpression::AddExpression(Expression *x, Expression *y) : BinaryExpression(x, y){}

int AddExpression::solve(){
    return x->solve() + y->solve();
}
