#include "dotoverloadexception.h"

/*
 * Kelas DotOverloadException: kelas Exception ini ada untuk menghandle error operator dot (.) yang melebihi 1 di operand
*/

//Konstruktor
DotOverloadException::DotOverloadException(int nDot, int dext){
    //set atribut dengan variabel di konstruktor
    this->nDot = nDot;
    this->dext = dext;

    //set errMessage
    setErrMessage();
}


void DotOverloadException::setErrMessage(){
    //pesan kesalahan : menunjukkan berapa banyak dot yang ada di satu operand. Harusnya hanya satu
    string temp = "Error dot overload at operand ";
    if(dext){
        temp += "kanan";
    } else {
        temp += "kiri";
    }

    temp += ": There are " + to_string(this->nDot) + " dots. Use only one in operand";
    this->errMessage = temp;
}
