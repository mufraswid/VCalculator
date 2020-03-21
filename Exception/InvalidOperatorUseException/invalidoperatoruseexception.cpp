#include "invalidoperatoruseexception.h"

/*
 * Kelas InvalidOperatorUseException: kelas Exception ini ada untuk menghandle error operator yang digunakan tidak di tempat seharusnya
*/

//Konstruktor
InvalidOperatorUseException::InvalidOperatorUseException(char invOp, int idx, int dext){
    //set atribut dengan variabel di konstruktor
    this->invOp = invOp;
    this->idx = idx;
    this->dext = dext;

    //set errMessage
    setErrMessage();
}


void InvalidOperatorUseException::setErrMessage(){
    //index di operand dan dexterity dari operand
    string temp = "Error penggunaan operator di operand ";
    if(!dext){
        temp += "kiri:";
    } else {
        temp += "kanan:";
    }

    temp += to_string(idx) + "\n";

    //kesalahan bila + didepan : Tidak perlu ada operator + didepan operand
    if(invOp == '+' && idx == 0){
        temp += "Operator (+): Tidak perlu digunakan didepan operand";
        this->errMessage = temp;
        return;
    }

    //kesalahan bila . didepan : Tidak bisa ada operator . didepan operand
    if(invOp == '.' && idx == 0){
        temp += "Operator (.): Tidak bisa digunakan di awal operand";
        this->errMessage = temp;
        return;
    }

    //kesalahan bila . dibelakang : Tidak bisa ada operator . dibelakang operand
    if(invOp == '.' && idx == -1){
        temp += "Operator (.): Tidak bisa digunakan di akhir operand";
        this->errMessage = temp;
        return;
    }

    //kasus lain : Operator sembarang berada di tempat yang tidak seharusnya
    temp += "Operator (" + string(1, invOp) + "): Penggunaan operator salah";

    //set pesan kesalahan
    this->errMessage = temp;
}
