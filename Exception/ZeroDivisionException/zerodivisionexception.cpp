#include "zerodivisionexception.h"

/*
 * Kelas ZeroDivisionException: kelas Exception ini ada untuk menghandle error pembagian dengan nol
*/

//Konstruktor
ZeroDivisionException::ZeroDivisionException(){
    //set errMessage
    setErrMessage();
}

void ZeroDivisionException::setErrMessage(){
    //pesan kesalahan : tidak bisa membagi dengan nol
    this->errMessage = "Cannot divide with zero!";
}
