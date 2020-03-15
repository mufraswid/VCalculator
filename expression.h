#ifndef EXPRESSION_H
#define EXPRESSION_H

template<class T>
class Expression {
public:
    Expression(){};
    virtual T solve() = 0;
};

#endif
