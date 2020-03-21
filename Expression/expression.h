#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <bits/stdc++.h>
using namespace std;

template<class T>
class Expression {
public:
    Expression(){};
    virtual T solve() = 0;
};

#endif
