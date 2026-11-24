// Lab_09_1.cpp
// Єфіменко Софія
// Лабораторна робота № 9.1
// Головний файл проєкту – функція main
// Варіант 8

#include <iostream>
#include <iomanip>
#include <cmath>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;
using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "Variant 8: Taylor series for arctg(x) (x > 1)" << endl;
    cout << "Enter x_p (x > 1): "; cin >> x_p;
    cout << "Enter x_k        : "; cin >> x_k;
    cout << "Enter dx         : "; cin >> dx;
    cout << "Enter eps        : "; cin >> e;
    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
    cout << "|    x    |   arctg(x)   |      s       |    |s-f|    |  n  |" << endl;
    cout << "-------------------------------------------------------------" << endl;

    x = x_p;
    while (x <= x_k) {
        sum();
        double exact = atan(x);
        double diff = fabs(s - exact);

        cout << "|" << setw(9) << fixed << setprecision(4) << x << " "
             << "|" << setw(14) << fixed << setprecision(7) << exact << " "
             << "|" << setw(14) << fixed << setprecision(7) << s << " "
             << "|" << setw(12) << scientific << setprecision(2) << diff << " "
             << "|" << setw(5) << n << " |" << endl;

        x += dx;
    }

    cout << "-------------------------------------------------------------" << endl;

    return 0;
}
