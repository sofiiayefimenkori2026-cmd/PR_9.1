// sum.cpp
// Єфіменко Софія
// Лабораторна робота № 9.1
// Файл реалізації функції обчислення суми ряду Тейлора
// Варіант 8

#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() {
    const double PI = 4.0 * atan(1.0);
    n = 0;
    a = -1.0 / x;
    s = PI / 2.0 + a;
    do {
        n++;
        dod();
        s += a;
    } while (fabs(a) > e);
}
