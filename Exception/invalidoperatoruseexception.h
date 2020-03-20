#ifndef INVALIDOPERATORUSEEXCEPTION_H
#define INVALIDOPERATORUSEEXCEPTION_H

#include "baseexception.h"

class InvalidOperatorUseException : public BaseException{
private:
    char invOp;
    int idx;
    int dext;

public:
    InvalidOperatorUseException(char invOp, int idx, int dext);
    void setErrMessage();
};

#endif // INVALIDOPERATORUSEEXCEPTION_H
