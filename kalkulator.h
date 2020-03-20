#ifndef KALKULATOR_H
#define KALKULATOR_H

#include <QMainWindow>

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
};

#endif // KALKULATOR_H
