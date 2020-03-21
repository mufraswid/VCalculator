#include "nooperatorexception.h"

/*
 * Kelas NoOperatorException: kelas Exception ini ada untuk menghandle error operand yang tidak mempunyai operator apapun
*/


//Konstruktor
NoOperatorException::NoOperatorException(){
    //set errMessage
    setErrMessage();
}


void NoOperatorException::setErrMessage(){
    //pesan kesalahan : Tidak ada operator yang dimasukkan pengguna
    this->errMessage = "Tidak ada operator!";
}
