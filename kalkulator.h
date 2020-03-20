#ifndef KALKULATOR_H
#define KALKULATOR_H

#include <QMainWindow>
#include <bits/stdc++.h>
using namespace std;

namespace Ui {
class Kalkulator;
}

class Kalkulator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kalkulator(QWidget *parent = 0);
    ~Kalkulator();

private:
    Ui::Kalkulator *ui;

private slots:
    void onClick();
    void onClickEq();
    void onClickAC();
    void onClickDel();
    void onClickMC();
    void onClickMR();
};

#endif // KALKULATOR_H
