#ifndef NOOPERATOREXCEPTION_H
#define NOOPERATOREXCEPTION_H

#include "../BaseException/baseexception.h"

class NoOperatorException : public BaseException{
public:
    NoOperatorException();
    void setErrMessage();
};

#endif // NOOPERATOREXCEPTION_H
