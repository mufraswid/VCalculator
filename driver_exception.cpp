#include "Exception/BaseException/baseexception.h"
#include "Exception/DecExponentNegBaseException/decexponentnegbaseexception.h"
#include "Exception/DecimalModException/decimalmodexception.h"
#include "Exception/DotOverloadException/dotoverloadexception.h"
#include "Exception/InvalidOperatorUseException/invalidoperatoruseexception.h"
#include "Exception/NoOperatorException/nooperatorexception.h"
#include "Exception/RootNegativeException/rootnegativeexception.h"
#include "Exception/ZeroDivisionException/zerodivisionexception.h"
#include "Exception/ZeroModException/zeromodexception.h"
#include <iostream>
int main(){
    BaseException *exception;
    cout << "--------------------------------------- Pengujian Exception -----------------------------------------" << endl;
    cout << "Pengujian kelas DecExponentNegBaseException:" << endl;
    exception = new DecExponentNegBaseException();
    exception->getErrMessage();
    cout << "\n\n-------------------------------------------" << endl;
    cout << "Pengujian kelas DecimalModException:" << endl;
    exception = new DecimalModException(1);
    exception->getErrMessage();
    exception = new DecimalModException(0);
    exception->getErrMessage();
    cout << "\n\n-------------------------------------------" << endl;
    cout << "Pengujian kelas DotOverloadException:" << endl;
    exception = new DotOverloadException(2,1);
    exception->getErrMessage();
    exception = new DotOverloadException(2,0);
    exception->getErrMessage();
    cout << "\n\n-------------------------------------------" << endl;
    cout << "Pengujian kelas InvalidOperatorUseException:" << endl;
    exception = new InvalidOperatorUseException('+',0,1);
    exception->getErrMessage();
    exception = new InvalidOperatorUseException('+',0,0);
    exception->getErrMessage();
    exception = new InvalidOperatorUseException('.',0,1);
    exception->getErrMessage();
    exception = new InvalidOperatorUseException('.',-1,1);
    exception->getErrMessage();
    exception = new InvalidOperatorUseException('.',0,0);
    exception->getErrMessage();
    exception = new InvalidOperatorUseException('.',-1,0);
    exception->getErrMessage();
    cout << "\n\n-------------------------------------------" << endl;
    cout << "Pengujian kelas NoOperatorException:" << endl;
    exception = new NoOperatorException();
    exception->getErrMessage();
    cout << "\n\n-------------------------------------------" << endl;
    cout << "Pengujian kelas RootNegativeException:" << endl;
    exception = new RootNegativeException();
    exception->getErrMessage();
    cout << "\n\n-------------------------------------------" << endl;
    cout << "Pengujian kelas ZeroDivisionException:" << endl;
    exception = new ZeroDivisionException();
    exception->getErrMessage();
    cout << "\n\n-------------------------------------------" << endl;
    cout << "Pengujian kelas ZeroModException:" << endl;
    exception = new ZeroModException();
    exception->getErrMessage();
    return 0;
}