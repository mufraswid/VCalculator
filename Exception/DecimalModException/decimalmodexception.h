#ifndef DECIMALMODEXCEPTION_H
#define DECIMALMODEXCEPTION_H

#include "../BaseException/baseexception.h"

/*
 * Kelas DecimalModException: kelas Exception ini ada untuk menghandle error modulo dengan desimal
*/


class DecimalModException : public BaseException{
private:
    int dext;

public:
    //Konstruktor
    DecimalModException(int dext);

    //setErrMessage() : set atribut errMessage dari superclass BaseException untuk error
    void setErrMessage();
};

#endif // DECIMALMODEXCEPTION_H
