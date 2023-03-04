#include <iostream>
#include "rational.h"

using namespace std;

rational operator-(rational& r1, rational& r2) {
	rational temp;
	int t_a, t_b;
	t_b = r1.b * r2.b;
	t_a = r1.a * r2.b - r2.a * r1.b;
	temp.set(t_a, t_b);
	return temp;
};

int main() {
	setlocale(LC_ALL, "rus");
	int n, a, b;
	cout << "Введите количество дробей: ";
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

	int n1, n2;

	cout << "\nВведите номера дробей, которые хотите сложить: ";
	cin >> n1 >> n2;
	rational res = rational();
	res = mas[n1 - 1] + mas[n2 - 1];
	cout << "Результат: ";
	res.show();

	cout << "\nВведите номера дробей, которые хотите вычесть друг из друга: ";
	cin >> n1 >> n2;
	res = mas[n1 - 1] - mas[n2 - 1];
	cout << "Результат: ";
	res.show();

	cout << "\nВведите № дроби, для выполнения ++x: ";
	cin >> n1;
	cout << "Результат: ";
	res = ++mas[n1 - 1];
	res.show();

	for (int i = 0; i < n; i++) {
		cout << "Дробь №" << i + 1 << ": ";
		mas[i].show();
	}

	cout << "\nВведите № дроби, для выполнения x++: ";
	cin >> n1;
	cout << "Результат: ";
	mas[n1 - 1]++;
	res = mas[n1 - 1];
	res.show();

	for (int i = 0; i < n; i++) {
		cout << "Дробь №" << i + 1 << ": ";
		mas[i].show();
	}

	cout << "\nВведите номера дробей, которые надо проверить на эквивалентность: ";
	cin >> n1 >> n2;
	if (mas[n1-1] == mas[n2-1]) cout << "Дроби эквивалентны" << endl;
	else cout << "Дроби не эквивалентны" << endl;

	cout << "\nВведите номера дробей, которые надо сравнить: ";
	cin >> n1 >> n2;
	mas[n1-1] > mas[n2-1];

	cout << "\nВведите номер дроби, к которой нужно присвоить значение другой, а после пробела номер присваиваемой дроби: ";
	cin >> n1 >> n2;
	mas[n1 - 1] = mas[n2 - 1];
	cout << "Теперь дробь №" << n1 << " равна ";
	mas[n1 - 1].show();

	for (int i = 0; i < n; i++) {
		cout << "Дробь №" << i + 1 << ": ";
		mas[i].show();
	}

	delete[] mas;
	return 0;
}