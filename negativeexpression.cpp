#include "negativeexpression.h"
#include <iostream>
using namespace std;

NegativeExpression::NegativeExpression(Expression *x) : UnaryExpression(x){}

int NegativeExpression::solve(){
    return (x->solve())*-1;
}
