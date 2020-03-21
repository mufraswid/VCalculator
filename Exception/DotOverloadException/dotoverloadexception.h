#ifndef DOTOVERLOADEXCEPTION_H
#define DOTOVERLOADEXCEPTION_H

#include "../BaseException/baseexception.h"

/*
 * Kelas DotOverloadException: kelas Exception ini ada untuk menghandle error operator dot (.) yang melebihi 1 di operand
*/

class DotOverloadException : public BaseException{
private:
    int nDot;  //atribut banyak dot yang ditemukan
    int dext;  //dexterity: operand kanan atau kiri yang terkena exception

public:
    //Konstruktor
    DotOverloadException(int nDot, int dext);

    //setErrMessage() : set atribut errMessage dari superclass BaseException untuk error
    void setErrMessage();
};

#endif // DOTOVERLOADEXCEPTION_H
