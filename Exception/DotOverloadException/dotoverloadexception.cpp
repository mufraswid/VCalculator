#include "dotoverloadexception.h"

DotOverloadException::DotOverloadException(int nDot, int dext){
    this->nDot = nDot;
    this->dext = dext;
    setErrMessage();
}

void DotOverloadException::setErrMessage(){
    string temp = "Error dot overload at operand ";
    if(dext){
        temp += "kanan";
    } else {
        temp += "kiri";
    }

    temp += ": There are " + to_string(this->nDot) + " dots. Use only one in operand";
    this->errMessage = temp;
}
