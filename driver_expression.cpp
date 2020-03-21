#include "Expression/TerminalExpression/terminalexpression.h"
#include "Expression/AddExpression/addexpression.h"
#include "Expression/SubstractExpression/substractexpression.h"
#include "Expression/MultiplyExpression/multiplyexpression.h"
#include "Expression/DivisionExpression/divisionexpression.h"
#include "Expression/RootExpression/rootexpression.h"
#include "Expression/PowerExpression/powerexpression.h"
#include "Expression/ModExpression/modexpression.h"
#include "Expression/SinExpression/sinexpression.h"
#include "Expression/CosExpression/cosexpression.h"
#include "Expression/TanExpression/tanexpression.h"
#include <iostream>
using namespace std;

int main(){
    double ans, opr1, opr2;
    Expression<double> *result;
    cout << "Operand 1: ";
    cin >> opr1;
    cout << "Operand 2: ";
    cin >> opr2;

    TerminalExpression<double> A(opr1);
    TerminalExpression<double> B(opr2);

    result = new AddExpression<double>(&A, &B);
    ans = result->solve();
    cout << opr1 << " + " << opr2 << " = " << ans << endl;
    result = new SubstractExpression<double>(&A, &B);
    ans = result->solve();
    cout << opr1 << " - " << opr2 << " = " << ans << endl;
    result = new MultiplyExpression<double>(&A, &B);
    ans = result->solve();
    cout << opr1 << " * " << opr2 << " = " << ans << endl;
    result = new DivisionExpression<double>(&A, &B);
    ans = result->solve();
    cout << opr1 << " / " << opr2 << " = " << ans << endl;
    result = new RootExpression<double>(&A);
    ans = result->solve();
    cout << "Root of " << opr1 << " = " << ans << endl;
    result = new PowerExpression<double>(&A, &B);
    ans = result->solve();
    cout << opr1 << "^" << opr2 << " = " << ans << endl;
    result = new ModExpression<double>(&A, &B);
    ans = result->solve();
    cout << opr1 << " % " << opr2 << " = " << ans << endl;
    result = new SinExpression<double>(&A);
    ans = result->solve();
    cout << "Sin(" << opr1 << ") = " << ans << endl;
    result = new CosExpression<double>(&A);
    ans = result->solve();
    cout << "Cos(" << opr1 << ") = " << ans << endl;
    result = new TanExpression<double>(&A);
    ans = result->solve();
    cout << "Tan(" << opr1 << ") = " << ans << endl;

    return 0;
}
