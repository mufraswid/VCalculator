#include "invalidoperatoruseexception.h"

InvalidOperatorUseException::InvalidOperatorUseException(char invOp, int idx, int dext){
    this->invOp = invOp;
    this->idx = idx;
    this->dext = dext;
    setErrMessage();
}

void InvalidOperatorUseException::setErrMessage(){
    string temp = "Error penggunaan operator di operand";
    if(!dext){
        temp += "kiri:";
    } else {
        temp += "kanan:";
    }

    temp += to_string(idx) + "\n";

    if(invOp == '+' && idx == 0){
        temp += "Operator + tidak perlu digunakan didepan operand";
        this->errMessage = temp;
        return;
    }

    temp += "Error penggunaan operator +: Penggunaan operator salah";

    this->errMessage = temp;
}
