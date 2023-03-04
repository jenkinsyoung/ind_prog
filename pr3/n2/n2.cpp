#include <iostream>
#include "rational.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n, a, b;
	cout<<"введите количество дробей: ";
	cin >> n;
	rational* mas = new rational[n];
	for (int i = 0; i < n; i++) {
		cout << "\nВведите числитель и знаменатель дроби через пробел: ";
		cin >> a >> b;
		mas[i] = rational(a, b);
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "Дробь №" << i + 1 << ": ";
		mas[i].show();
	}
	int key=0;
	while (key != -1) {
		cout << "Для изменения дроби введите номер дроби от 1-n. Если Вы не хотите изменять дроби, введите -1\n";
		cin >> key;
		if (key != -1) {
			cout << "Введите числитель и знаменатель: ";
			cin >> a >> b;
			mas[key-1].set(a, b);
			cout << "Дробь изменена на ";
			mas[key - 1].show();
		}
		else {
			cout << "\nВесь список дробей с изменениями:\n";
			for (int i = 0; i < n; i++) {
				cout << "Дробь №" << i + 1 << ": ";
				mas[i].show();
			}
		}
	}
	
	delete[] mas;
	return 0;
}