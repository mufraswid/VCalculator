#include "zeromodexception.h"

/*
 * Kelas ZeroModException: kelas Exception ini ada untuk menghandle error modulo dengan nol
*/

//Konstruktor
ZeroModException::ZeroModException(){
    //set errMessage
    setErrMessage();
}

void ZeroModException::setErrMessage(){
    //pesan kesalahan : tidak bisa membagi dengan nol
    this->errMessage = "Tidak bisa modulo dengan nol!";
}
