#include "Parser/parser.h"
#include <iostream>
using namespace std;
int main(){
    cout << "--------------------------------------- Pengujian Parser -----------------------------------------" << endl;
    cout << "Pengujian kelas Parser:" << endl;
    cout << "Masukkan Ekspresi: ";
    string expression;
    cin >> expression;
    Parser p(expression);
    try{                                            
        p.parseEquation();                          
    } catch(BaseException* e){                      
        cout << e->getErrMessage();                
    }
    cout << "Operand Kiri: " << p.getLeftSide() << endl;
    cout << "Operand Kanan: " << p.getRightSide() << endl;
    cout << "Operator: " << p.getOperator << endl;
    return 0;
}
