#include "eq2.h" 
#include <iostream> 

using namespace std;

eq2 operator + (eq2& e1, eq2& e2) {
    eq2 temp;
    temp.set(e1.get_a() + e2.get_a(), e1.get_b() + e2.get_b(), e1.get_c() + e2.get_c());
    return temp;
}

int main() {

    setlocale(LC_ALL, "rus");
    double a, b, c;
    cout << "Введите коэффициенты первого уравнения через пробел:" << endl;
    cin >> a >> b >> c;
    eq2 exmpl(a, b, c);
    exmpl.find_X();
    double n;
    cout << "Введите значение х:" << endl;
    cin >> n;
    cout << exmpl.find_Y(n) << endl;
    double a1, b1, c1;
    cout << "Введите коэффициенты второго уравнения через пробел:" << endl;
    cin >> a1 >> b1 >> c1;
    eq2 exmpl2(a1, b1, c1);
    exmpl2.find_X();
    cout << "Введите значение х:" << endl;
    cin >> n;
    cout << exmpl2.find_Y(n) << endl;
    eq2 res = exmpl + exmpl2;
    cout << "После сложения уравнений получим: " << res.get_a() << "*x^2 + " << res.get_b() << "*x + " << res.get_c() << " = 0" << endl;

    return 0;
}

