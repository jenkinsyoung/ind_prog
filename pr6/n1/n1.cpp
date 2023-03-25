#include <iostream>
#include "cone.h"

using namespace std;

ostream& operator<<(ostream& out, const cone obj) {
    out << "(" << obj.x << "; " << obj.y << "; " << obj.z << "); r=" << obj.radius << " " << "h=" << obj.height << "\n";
    return out;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cone c1(3, 7); 
    cone c2(1, 2, 3, 5, 10);

    cout << "Конус 1: " << c1;
    cout << "Площадь поверхности: " << c1.area() << "\n";
    cout << "Объем: " << c1.volume() << "\n";

    cout << "Конус 2: " << c2;
    cout << "Площадь поверхности: " << c2.area() << "\n";
    cout << "Объем: " << c2.volume() << "\n";

    int size, n;
    cout << "Введите количество конусов: ";
    cin >> size;
    cone* mas = new cone[size];
    for (int i = 0; i < size; i++) {
        cout << "Введите 0 - если конус с центром в начале координат. Введите 1 - конус произвольный: ";
        cin >> n;
        if (n == 0) {
            double r, h;
            cout << "Введите измерения через пробел: ";
            cin >> r >> h;
            mas[i].setRadius(r);
            mas[i].setHeight(h);
        }
        else{
            double a, b, c, r1, h1;
            cout << "Введите измерения через пробел: ";
            cin >> a >> b >> c >> r1 >> h1;
            mas[i].setCoordinate(a, b, c);
            mas[i].setRadius(r1);
            mas[i].setHeight(h1);
        }   
    }
    for (int i = 0; i < size; i++) {
        cout << "Конус "<<i+3<< ": "<<mas[i];
        cout << "Площадь поверхности: " << mas[i].area() << "\n";
        cout << "Объем: " << mas[i].volume() << "\n";
    }
    return 0;
}