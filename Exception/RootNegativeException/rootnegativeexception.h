#ifndef ROOTNEGATIVEEXCEPTION_H
#define ROOTNEGATIVEEXCEPTION_H

#include "../BaseException/baseexception.h"

class RootNegativeException : public BaseException{
public:
    RootNegativeException();
    void setErrMessage();
};

#endif // ROOTNEGATIVEEXCEPTION_H
