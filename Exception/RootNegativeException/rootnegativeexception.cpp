#include "rootnegativeexception.h"

/*
 * Kelas RootNegativeException: kelas Exception ini ada untuk menghandle error operand negatif saat melakukan operasi sqrt
*/

//Konstruktor
RootNegativeException::RootNegativeException(){
    //set errMessage
    setErrMessage();
}

void RootNegativeException::setErrMessage(){
    //pesan kesalahan : Operand tidak boleh negatif
    this->errMessage = "Operand of a root cannot be negative!";
}
