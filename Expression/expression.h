#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <bits/stdc++.h>
using namespace std;

/*
 * Kelas Expression: adalah baseclass untuk modul Expression. Kelas ini menggunakan konsep generic untuk menentukan tipe ekspresi yang
 * dievaluasi nantinya
*/

template<class T>
class Expression {
public:
    //Konstruktor
    Expression(){};

    //solve() : metode virtual yang digunakan oleh Expression untuk mengevaluasi ekspresi yang ada. Diimplementasikan oleh
    //          kelas turuna dari Expression
    virtual T solve() = 0;
};

#endif
