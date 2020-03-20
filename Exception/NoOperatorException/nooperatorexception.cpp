#include "nooperatorexception.h"

NoOperatorException::NoOperatorException(){
    setErrMessage();
}

void NoOperatorException::setErrMessage(){
    this->errMessage = "Tidak ada operator!";
}
