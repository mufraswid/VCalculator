#ifndef DECEXPONENTNEGBASEEXCEPTION_H
#define DECEXPONENTNEGBASEEXCEPTION_H

#include "../BaseException/baseexception.h"

/*
 * Kelas DecExponentNegBaseException: kelas Exception ini ada untuk menghandle error exponen bilangan negatif dengan bilangan desimal
*/


class DecExponentNegBaseException : public BaseException{
private:
    int dext;

public:
    //Konstruktor
    DecExponentNegBaseException();

    //setErrMessage() : set atribut errMessage dari superclass BaseException untuk error
    void setErrMessage();
};

#endif // DECEXPONENTNEGBASEEXCEPTION_H
