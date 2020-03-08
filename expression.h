#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
public:
    Expression();
    virtual int solve() = 0;
    virtual void setValue(int a) = 0;
};

#endif
