#include "rootnegativeexception.h"

RootNegativeException::RootNegativeException(){
    setErrMessage();
}

void RootNegativeException::setErrMessage(){
    this->errMessage = "Operand of a root cannot be negative!";
}
