#ifndef ZERODIVISIONEXCEPTION_H
#define ZERODIVISIONEXCEPTION_H

#include "../BaseException/baseexception.h"

/*
 * Kelas ZeroDivisionException: kelas Exception ini ada untuk menghandle error pembagian dengan nol
*/


class ZeroDivisionException : public BaseException{
public:
    //Konstruktor
    ZeroDivisionException();

    //setErrMessage() : set atribut errMessage dari superclass BaseException untuk error
    void setErrMessage();
};

#endif // ZERODIVISIONEXCEPTION_H
