#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include<bits/stdc++.h>
using namespace std;

/*
 * Kelas BaseException: baseclass untuk modul Exception
*/

class BaseException {
protected:
    string errMessage; //atribut untuk menyimpan pesan error yang ditemukan

public:
    //setErrMessage() : fungsi virtual set errMessage yang akan diimplementasikan oleh kelas turunan BaseException
    virtual void setErrMessage() = 0;

    //getErrMessage() : mengembalikan pesan error yang telah diset sebelumnya
    string getErrMessage(){ //
        return this->errMessage;
    }
};

#endif // BASEEXCEPTION_H
