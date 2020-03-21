#ifndef NOOPERATOREXCEPTION_H
#define NOOPERATOREXCEPTION_H

#include "../BaseException/baseexception.h"

/*
 * Kelas NoOperatorException: kelas Exception ini ada untuk menghandle error operand yang tidak mempunyai operator apapun
*/

class NoOperatorException : public BaseException{
public:
    //Konstruktor
    NoOperatorException();

    //setErrMessage() : set atribut errMessage dari superclass BaseException untuk error
    void setErrMessage();
};

#endif // NOOPERATOREXCEPTION_H
