#include "figure.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	figure mas[3];
	float x1, x2, x3, x4;
	float y1, y2, y3, y4;
	for (int i = 0; i < 3; i++) {
		cout << "Введите координаты точек A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4) для четырехугольника №" << i + 1 << " через пробел:" << endl;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		mas[i] = figure(x1, x2, x3, x4, y1, y2, y3, y4);
	}
	for (int i = 0; i < 3; i++) {
		mas[i].show();
		cout << "Данный четырехугольник:\n";
		if (mas[i].is_prug()) {
			cout << "прямоугольник" << endl;
		}
		else cout << "не прямоугольник" << endl;

		if (mas[i].is_romb()) {
			cout << "ромб" << endl;
		}
		else cout << "не ромб" << endl;

		if (mas[i].is_square()) {
			cout << "квадрат" << endl;
		}
		else cout << "не квадрат" << endl;

		if (mas[i].is_in_circle()) {
			cout << "можно вписать в окружность" << endl;
		}
		else cout << "нельзя вписать в окружность" << endl;
		if (mas[i].is_out_circle()) {
			cout << "в четырёхугольник может быть вписана окружность" << endl;
		}
		else cout << "в четырёхугольник НЕ может быть вписана окружность" << endl;
	}
	return 0;
}