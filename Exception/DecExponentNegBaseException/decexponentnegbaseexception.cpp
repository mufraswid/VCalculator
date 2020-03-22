#include "decexponentnegbaseexception.h"

/*
 * Kelas DecExponentNegBaseException: kelas Exception ini ada untuk menghandle error modulo dengan desimal
*/

//Konstruktor
DecExponentNegBaseException::DecExponentNegBaseException(){
    setErrMessage();
}

void DecExponentNegBaseException::setErrMessage(){
    this->errMessage = "Tidak bisa memangkatkan bilangan negatif dengan bilangan desimal!";
}
