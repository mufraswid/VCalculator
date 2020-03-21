#ifndef ZEROMODEXCEPTION_H
#define ZEROMODEXCEPTION_H

#include "../BaseException/baseexception.h"

/*
 * Kelas ZeroModException: kelas Exception ini ada untuk menghandle error modulo dengan nol
*/


class ZeroModException : public BaseException{
public:
    //Konstruktor
    ZeroModException();

    //setErrMessage() : set atribut errMessage dari superclass BaseException untuk error
    void setErrMessage();
};

#endif // ZEROMODEXCEPTION_H
