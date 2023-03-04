#include "eq2.h"
#include <iostream>

using namespace std;

eq2::eq2() :a(0), b(0), c(0), D(0) {};

eq2::eq2(double a1, double b1, double c1) : a(a1), b(b1), c(c1) {
    D = b * b - 4 * a * c;
}

void eq2::set(double a1, double b1, double c1) {
    a = a1;
    b = b1;
    c = c1;
}

double eq2::find_X() {
    if (D < 0) {
        cout << "Корней нет" << endl;
        return 0;
    }
    else {
        if (D == 0) {
            cout << "Корень один: " << endl;
            double x = (-b - sqrt(D)) / (2 * a);
            cout << x << endl;
            return x;
        }
        else {
            cout << "Корней 2, наибольший: " << endl;
            double x1 = (-b - sqrt(D)) / (2 * a);
            double x2 = (-b + sqrt(D)) / (2 * a);
            if (x1 > x2) {
                cout << x1 << endl;
                return x1;
            }
            else {
                cout << x2 << endl;
                return x2;
            }
        }
    }
}

double eq2::find_Y(double x1) {
    double res = a * x1 * x1 + b * x1 + c;
    return res;
}
double eq2::get_a() {
    return a;
}
double eq2::get_b() {
    return b;
}
double eq2::get_c() {
    return c;
}