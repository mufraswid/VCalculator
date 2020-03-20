#ifndef DOTOVERLOADEXCEPTION_H
#define DOTOVERLOADEXCEPTION_H

#include "../BaseException/baseexception.h"

class DotOverloadException : public BaseException{
private:
    int nDot;
    int dext;

public:
    DotOverloadException(int nDot, int dext);
    void setErrMessage();
};

#endif // DOTOVERLOADEXCEPTION_H
