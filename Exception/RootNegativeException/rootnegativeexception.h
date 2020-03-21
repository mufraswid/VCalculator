#ifndef ROOTNEGATIVEEXCEPTION_H
#define ROOTNEGATIVEEXCEPTION_H

#include "../BaseException/baseexception.h"

/*
 * Kelas RootNegativeException: kelas Exception ini ada untuk menghandle error operand negatif saat melakukan operasi sqrt
*/


class RootNegativeException : public BaseException{
public:
    //Konstruktor
    RootNegativeException();

    //setErrMessage() : set atribut errMessage dari superclass BaseException untuk error
    void setErrMessage();
};

#endif // ROOTNEGATIVEEXCEPTION_H
