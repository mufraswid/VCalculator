#include "parser.h"

/*
 * Kelas Parser: adalah kelas untuk parsing input dari pengguna sebagai satu ekspresi yang bisa dievaluasikan
*/

//Konstruktor
Parser::Parser(QString eq){
    //set atribut dengan parameter; operator di set 'n' untuk none
    this->equation = eq.toStdString();
    this->oper = 'n';
}

//Konstruktor Overload
Parser::Parser(string eq){
    //set atribut dengan parameter; operator di set 'n' untuk none
    this->equation = eq;
    this->oper = 'n';
}

//getter operand kiri
double Parser::getLeftSide(){
    return this->leftSide;
}

//getter operand kanan
double Parser::getRightSide(){
    return this->rightSide;
}

//getter operator
char Parser::getOperator(){
    return this->oper;
}

void Parser::parseEquation(){
    string eq = this->equation;  //ubah eq ke std::string

    if(eq[0] == 'r' || eq[0] == 's' || eq[0] == 'c' || eq[0] == 't'){       //PROSES OPERATOR UNER:
        this->oper = eq[0];                                                 //  set operator
        scanOperand(eq.substr(1), 0);                                       //  scan operand yang ingin dievaluasi ke ekspresi
        this->leftSide = strToDbl(eq.substr(1));                            //  ubah ke double dari std::string
        return;                                                             //  selesai, keluar dari fungsi
    }

    //throw InvalidOperatorUseException : bila ada operator selain op. uner dan (-) didepan ekspresi
    if(eq[0] == '+' || eq[0] == '*' || eq[0] == '/' || eq[0] == '.' || eq[0] == '^' || eq[0] == '%'){
        InvalidOperatorUseException* e = new InvalidOperatorUseException(eq[0], 0, 0);
        throw e;
    }

    //idx dimana operator berada
    int whereOp;
    for(whereOp = 1; whereOp < eq.length(); whereOp++){
        if(eq[whereOp] == '+' || eq[whereOp] == '-' || eq[whereOp] == '*' || eq[whereOp] == '/' || eq[whereOp] == '^' || eq[whereOp] == '%'){
            break;  //bila operator ketemu, break
        }
    }

    //throw NoOperatorException : bila tidak ada operator yang ditemukan
    if(whereOp == eq.length()){
        NoOperatorException* e = new NoOperatorException();
        throw e;
    }

    //set operator
    this->oper = eq[whereOp];
    string left = eq.substr(0, whereOp);        //set operand kiri dari substring eq di kiri operator
    string right = eq.substr(whereOp+1);        //set operand kanan dari substring eq di kanan operator

    //SCANNING OPERAND : BILA ADA KESALAHAN MAKA AKAN MELEMPAR EXCEPTION
    scanOperand(left, 0);
    scanOperand(right, 1);

    //Sudah lulus uji operand, set atribut left dan right ke hasil operand yang dikonversi ke double menggunakan strToDbl()
    this->leftSide = strToDbl(left);
    this->rightSide = strToDbl(right);

    //throw ZeroDivisionException : bila operator adalah pembagian dan operand kanan adalah 0
    if(this->oper == '/' && this->rightSide == 0){
        ZeroDivisionException* e = new ZeroDivisionException();
        throw e;
    }

    //throw ZeroModException : bila operator adalah modulo dan operand kanan adalah 0
    if(this->oper == '%' && this->rightSide == 0){
        ZeroModException* e = new ZeroModException();
        throw e;
    }

    bool isDecRight = this->rightSide - floor(this->rightSide) != 0;
    //throw DecExponentNegBaseException : bila operator adalah exp, operand kiri negatif, operand kanan adalah desimal
    if(this->oper == '^' && this->leftSide < 0 && isDecRight){
        DecExponentNegBaseException* e = new DecExponentNegBaseException();
        throw e;
    }

}

void Parser::scanOperand(string operand, int dext){
    int nDot = 0; //counter banyak titik desimal

    //throw InvalidOperatorUseException : bila ada operator di tengah-tengah operand atau di awal operand (selain (-))
    for(int i = 0; i < operand.length(); i++){
        if(operand[i] == '+' || operand[i] == '-' || operand[i] == '*' || operand[i] == '/' || operand[0] == 'r' || operand[0] == '^' || operand[0] == '%' || operand[0] == 's' || operand[0] == 'c' || operand[0] == 't'){
            if(operand[i] != '-' || i != 0){
                InvalidOperatorUseException* e = new InvalidOperatorUseException(operand[i], i, dext);
                throw e;
            }
        }

        //keep track banyak titik decimal
        if(operand[i] == '.'){
            //throw InvalidOperatorUseException : bila di akhir operand ada titik desimal
            if(i == operand.length()-1){
                InvalidOperatorUseException* e = new InvalidOperatorUseException(operand[i], -1, dext);
                throw e;
            } else {
                nDot++;     //tambah jumlah dot
            }
        }
    }

    //throw DotOverloadException : bila jumlah titik di satu operand melebihi 1
    if(nDot > 1){
        DotOverloadException* e = new DotOverloadException(nDot, dext);
        throw e;
    }

    //throw RootNegativeException : bila pada operasi akar kuadrat, operand merupakan bil. negatif
    if(this->oper == 'r' && operand[0] == '-'){
        RootNegativeException* e = new RootNegativeException();
        throw e;
    }

    bool isDec = strToDbl(operand) - floor(strToDbl((operand))) != 0;
    //throw DecimalModException : bila pada operasi modulo, terdapat operand yang merupakan bil. desimal
    if(this->oper == '%' && nDot > 0 && isDec){
        DecimalModException* e = new DecimalModException(dext);
        throw e;
    }
}

double Parser::strToDbl(string str){
    int dot; //letak titik desimal

    //mencari dimana titik desimal berada
    for(dot = 0; dot < str.length(); dot++){
        if(str[dot] == '.') break;
    }

    if(dot == str.length()){    //Tidak ada titik desimal, langsung ubah menggunakan std::stod()
        return stod(str);
    }

    double upper = stod(str.substr(0, dot));                    //ubah bagian integer ke double menggunakan stod(substring di kanan titik desimal)
    string lowerStr = str.substr(dot+1);                        //dapatkan bagian integer pecahan dari substring di kanan titik desimal
    double lower = stod(lowerStr) / pow(10, lowerStr.length()); //ubah bagian integer pecahan dengan stod(lowerStr) dibagi dengan 10^(banyakdigitlowerStr)

    return upper+lower; //kembalikan bagian integer + bagian desimal
}
