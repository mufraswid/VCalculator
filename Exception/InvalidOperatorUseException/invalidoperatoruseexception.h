#ifndef INVALIDOPERATORUSEEXCEPTION_H
#define INVALIDOPERATORUSEEXCEPTION_H

#include "../BaseException/baseexception.h"

/*
 * Kelas InvalidOperatorUseException: kelas Exception ini ada untuk menghandle error operator yang digunakan tidak di tempat seharusnya
*/

class InvalidOperatorUseException : public BaseException{
private:
    char invOp;     //operator yang dideteksi salah penggunaannya
    int idx;        //idx dimana operator berada di operand
    int dext;       //dexterity: operand kanan atau kiri yang terkena exception

public:
    //Konstruktor
    InvalidOperatorUseException(char invOp, int idx, int dext);

    //setErrMessage() : set atribut errMessage dari superclass BaseException untuk error
    void setErrMessage();
};

#endif // INVALIDOPERATORUSEEXCEPTION_H
