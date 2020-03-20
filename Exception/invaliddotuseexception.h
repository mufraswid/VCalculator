#ifndef INVALIDDOTUSEEXCEPTION_H
#define INVALIDDOTUSEEXCEPTION_H

#include "baseexception.h"

class InvalidDotUseException : public BaseException{
private:
    int nDot;
    int dext;

public:
    InvalidDotUseException(int nDot, int dext);
    void setErrMessage();
};
#endif // INVALIDDOTUSEEXCEPTION_H
