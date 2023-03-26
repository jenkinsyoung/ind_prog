#include <iostream>
#include "cone.h"

using namespace std;

istream& operator>>(istream& in, TruncatedCone& c) {
    in >> c.r >> c.R >> c.h;
    return in;
}

ostream& operator<<(ostream& out, TruncatedCone& c) {
    out << "r = " << c.r << ", R = " << c.R << ", h = " << c.h;
    return out;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    TruncatedCone T1(3, 4, 5), T2(2, 3, 4), T3(0, 0, 0);
    cout << "Для первого усеченного конуса" << endl;
    cout << T1 << endl;
    cout << "Площадь поверхности: " << T1.surface() << endl;
    cout << "Объем: " << T1.volume() << endl;
    cout << "Для второго усеченного конуса" << endl;
    cout << T2 << endl;
    cout << "Площадь поверхности: " << T2.surface() << endl;
    cout << "Объем: " << T2.volume() << endl;
    cout << (T1 == T2 ? "Равны" : "Не равны") << endl;
    

    cout << "Введите r, R и h для третьего усеченного конуса: ";
    cin >> T3;
    cout << "Для третьего усеченного конуса" << endl;
    cout << T3 << endl;
    cout << "Площадь поверхности: " << T3.surface() << endl;
    cout << "Объем: " << T3.volume() << endl;

    return 0;
}