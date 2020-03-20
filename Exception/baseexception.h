#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include<bits/stdc++.h>
using namespace std;

class BaseException {
protected:
    string errMessage;

public:
    virtual void setErrMessage() = 0;
    string getErrMessage(){
        return this->errMessage;
    }
};

#endif // BASEEXCEPTION_H
