#include "rootexpression.h"
#include <bits/stdc++.h>
using namespace std;

RootExpression::RootExpression(Expression *x) : UnaryExpression(x){}

int RootExpression::solve(){
    return sqrt(x->solve());
}
