#include "decimalmodexception.h"

/*
 * Kelas DecimalModException: kelas Exception ini ada untuk menghandle error modulo dengan desimal
*/

//Konstruktor
DecimalModException::DecimalModException(int dext){
    this->dext = dext;
    setErrMessage();
}

void DecimalModException::setErrMessage(){
    string temp = "Error untuk operand ";
    if(dext){
        temp += "kanan: ";
    } else {
        temp += "kiri: ";
    }

    temp += "Argumen modulo tidak boleh desimal!";
    //pesan kesalahan : tidak bisa modulo dengan desimal
    this->errMessage = temp;
}
