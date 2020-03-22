#include "kalkulator.h"
#include "ui_kalkulator.h"

Kalkulator::Kalkulator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kalkulator)
{
    ui->setupUi(this);

    //set input ke QString kosong
    input.setValue("");

    //set ans ke -0XDEADBEEF, menandakan ans kosong
    ans = -0xDEADBEEF;

    //display awal adalah 0
    setDisplay("0");

    //mengkoneksikan setiap QPushButton yang telah dibuat di GUI ke signal slot onClick
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++){
        QString name = "button" + QString::number(i);
        numButtons[i] = Kalkulator::findChild<QPushButton *>(name);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(onClick()));
    }

    //mengkoneksikan setiap button yang dibuat ke slot signal masing-masing
    connect(ui->addbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->subbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->mulbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->divbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->rootbutton, SIGNAL(released()), this, SLOT(onClickSqrt()));
    connect(ui->powbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->dotbutton, SIGNAL(released()), this, SLOT(onClick()));
    connect(ui->modbutton, SIGNAL(released()), this, SLOT(onClickMod()));
    connect(ui->ansbutton, SIGNAL(released()), this, SLOT(onClickAns()));
    connect(ui->sinbutton, SIGNAL(released()), this, SLOT(onClickSin()));
    connect(ui->cosbutton, SIGNAL(released()), this, SLOT(onClickCos()));
    connect(ui->tanbutton, SIGNAL(released()), this, SLOT(onClickTan()));
    connect(ui->eqbutton, SIGNAL(released()), this, SLOT(onClickEq()));
    connect(ui->acbutton, SIGNAL(released()), this, SLOT(onClickAC()));
    connect(ui->delbutton, SIGNAL(released()), this, SLOT(onClickDel()));
    connect(ui->mcbutton, SIGNAL(released()), this, SLOT(onClickMC()));
    connect(ui->mrbutton, SIGNAL(released()), this, SLOT(onClickMR()));
}

//Destruktor
Kalkulator::~Kalkulator()
{
    delete ui;
}

//metode onClick
void Kalkulator::onClick(){
    QPushButton *clicked = (QPushButton *)sender();
    QString value = clicked->text();        //mengambil value dari text button yang memanggil onClick
    input.setValue(input.solve()+value);    //memasukkan value tersebut ke string input
    setDisplay();                           //menampilkan eq ke layar
}

void Kalkulator::onClickSqrt(){
    input.setValue(input.solve()+QString("r"));     //memasukkan value 'r' untuk sqrt ke string input
    setDisplay();                                   //menampilkan 'r' sebagai 'sqrt' ke layar
}

void Kalkulator::onClickAns(){
    if(ans != -0XDEADBEEF){
        input.setValue(input.solve()+QString::number(ans)); //memasukkan value ans ke string input
        setDisplay();                                       //menampilkan hasil ans ke layar
    }
}

void Kalkulator::onClickMod(){
    input.setValue(input.solve()+QString("%"));     //memasukkan value '%' untuk mod ke string input
    setDisplay();                                   //menampilkan '%' sebagai 'mod' ke layar
}

void Kalkulator::onClickSin(){
    input.setValue(input.solve()+QString("s"));     //memasukkan value 's' untuk sin ke string input
    setDisplay();                                   //menampilkan 's' sebagai 'sin' ke layar
}

void Kalkulator::onClickCos(){
    input.setValue(input.solve()+QString("c"));     //memasukkan value 'c' untuk cos ke string input
    setDisplay();                                   //menampilkan 'c' sebagai 'cos' ke layar
}

void Kalkulator::onClickTan(){
    input.setValue(input.solve()+QString("t"));     //memasukkan value 't' untuk tan ke string input
    setDisplay();                                   //menampilkan 't' sebagai 'tan' ke layar
}

void Kalkulator::onClickEq(){
    Parser parser(input.solve());                   //buat objek Parser untuk parsing input dari pengguna
    Expression<double> *result;                     //variabel expression untuk hasil evaluasi equation hasil parsing

    if(input.solve() == "") return; //if no inputs, return

    try{                                                                        //MULAI TRY-CATCH UNTUK ERROR HANDLING DARI PARSING INPUT
        parser.parseEquation();                                                 //      Parsing input masukan pengguna
    } catch(BaseException* e){                                                  //CATCH ERROR
        setDisplay(QString::fromStdString(e->getErrMessage()));                 //      tampilkan pesan error ke layar
        return;                                                                 //      hentikan proses parsing : BATAL
    }

    TerminalExpression<double> leftSide(parser.getLeftSide());                  //operand kiri hasil parsing
    TerminalExpression<double> rightSide(parser.getRightSide());                //operand kanan hasil parsing

    char oper = parser.getOperator();                                           //get operator dari parser untuk di cek evaluasi EXPRESSION:
    if(oper == '+'){                                                            //bila + : assign result ke ekspresi penjumlahan
        result = new AddExpression<double>(&leftSide, &rightSide);
    } else if(oper == '-'){                                                     //bila - : assign result ke ekspresi pengurangan
        result = new SubstractExpression<double>(&leftSide, &rightSide);
    } else if(oper == '*'){                                                     //bila * : assign result ke ekspresi perkalian
        result = new MultiplyExpression<double>(&leftSide, &rightSide);
    } else if(oper == '/'){                                                     //bila / : assign result ke ekspresi pembagian
        result = new DivisionExpression<double>(&leftSide, &rightSide);
    } else if(oper == 'r'){                                                     //bila r : assign result ke ekspresi akar kuadrat
        result = new RootExpression<double>(&leftSide);
    } else if(oper == '^'){                                                     //bila ^ : assign result ke ekspresi pangkat
        result = new PowerExpression<double>(&leftSide, &rightSide);
    } else if(oper == '%'){                                                     //bila % : assign result ke ekspresi modulo
        result = new ModExpression<double>(&leftSide, &rightSide);
    } else if(oper == 's'){                                                     //bila s : assign result ke operasi sin
        result = new SinExpression<double>(&leftSide);
    } else if(oper == 'c'){                                                     //bila c : assign result ke operasi cos
        result = new CosExpression<double>(&leftSide);
    } else if(oper == 't'){                                                     //bila t : assign result ke operasi tan
        result = new TanExpression<double>(&leftSide);
    }

    ans = result->solve();                                                      //simpan nilai result ke atribut ans
    setDisplay(QString::number(ans));                                           //tampilkan ke layar
    input.setValue("");                                                         //reset input ke QString kosong
}

void Kalkulator::onClickAC(){
    input.setValue("");                             //hilangkan input, set ke QString kosong
    setDisplay(QString("0"));                        //display 0 ke layar
    for(int i = 0; i < memory.size(); i++){
        memory.pop();                               //pop memory hingga kosong
    }
}

void Kalkulator::onClickDel(){
    string str = input.solve().toStdString();           //ubah input ke std::string
    if(str.length() <= 1){                              //BILA PANJANG = 1
        input.setValue("");                             //      set input kosong
        setDisplay(QString("0"));                       //      display 0 ke layar
    } else {                                            //BILA PANJANG > 1
        str = str.substr(0, str.length()-1);            //      ambil substring dari str kecuali paling akhir
        input.setValue(QString::fromStdString(str));    //      set ke input
        setDisplay();                                   //      tampilkan ke layar hasilnya
    }
}

void Kalkulator::onClickMC(){
    onClickEq();
    memory.push(ans);           //push ans ke queue memory
}

void Kalkulator::onClickMR(){
    if(!memory.empty()){                                                    //BILA MEMORY TIDAK KOSONG:
        input.setValue(input.solve()+QString::number(memory.front()));      //      masukkan head dari memory ke input
        setDisplay();                                                       //      tampilkan ke layar
        memory.pop();                                                       //      pop memory
    }
}

void Kalkulator::setDisplay(){
   string temp = "";
   string process = input.solve().toStdString();        //ubah input ke std::string
   for(int i = 0; i < process.length(); i++){           //cek semua char dari input untuk selanjutnya diubah ke sintaks di display
       if(process[i] == 'r'){                           //bila 'r' maka ubah ke 'sqrt'
           temp += "sqrt";
       } else if(process[i] == '%'){                    //bila '%' maka ubah ke 'mod'
           temp += "mod";
       } else if(process[i] == 's'){                    //bila 's' maka ubah ke 'sin'
           temp += "sin";
       } else if(process[i] == 'c'){                    //bila 'c' maka ubah ke 'cos'
           temp += "cos";
       } else if(process[i] == 't'){                    //bila 't' maka ubah ke 'tan'
           temp += "tan";
       } else {                                         //kasus lainnya: masukkan biasa ke temp
           temp += process[i];
       }
   }

   ui->display->setText(QString::fromStdString(temp));  //tampilkan ke layar!
}

void Kalkulator::setDisplay(QString a){
    ui->display->setText(a);            //menampilkan QString a ke layar (OVERLOAD)
}
