#include "rational.h"
#include <iostream>

using namespace std;

rational::rational() :a(0), b(1) {};

rational::rational(int a1, int b1) {
	if (b1 == 0) {
		cout << "На ноль делить нельзя. Дрбь изменена на 0/1" << endl;
		a = 0;
		b = 1;
	}
	else {
		if (a1 >= b1) {
			a1 = a1 % b1;
		}
		for (int i = 2; i < a1 + 1; i++) {
			if (a1 % i == 0 and b1 % i == 0) {
				a1 = a1 / i;
				b1 = b1 / i;
			}
		}
		a = a1;
		b = b1;
	}
};

void rational::set(int a1, int b1) {
	if (b1 == 0) {
		cout << "На ноль делить нельзя. Дрбь изменена на 0/1" << endl;
		a = 0;
		b = 1;
	}
	else {
		if (a1 >= b1) {
			a1 = a1 % b1;
		}
		for (int i = 2; i < a1 + 1; i++) {
			if (a1 % i == 0 and b1 % i == 0) {
				a1 = a1 / i;
				b1 = b1 / i;
			}
		}
		a = a1;
		b = b1;
	}
};

void rational::show() {
	cout << a << "/" << b << endl;
};

rational::~rational() {};

int rational::get_a() {
	return a;
};

int rational::get_b() {
	return b;
};

rational& rational::operator=(const rational& r) {
	this->a = r.a;
	this->b = r.b;
	return *this;
}

bool rational::operator== (const rational& r) {
	int a1, a2;
	if (this->b != r.b) {
		a1 = this->a * r.b;
		a2 = r.a * this->b;
	}
	else { a1 = this->a; a2 = r.a; }
	return (a1 == a2);
}

void rational::operator> (const rational & r) {
	int a1=0, a2=0;
	if (this->b != r.b) {
		a1 = this->a * r.b;
		a2 = r.a * this->b;
	}
	else { a1 = this->a; a2 = r.a; }
	if (a1 > a2) { cout << "Первая дробь больше" << endl; }
	else if (a2 > a1) { cout << "Вторая дробь больше" << endl; }
	else { cout << "Дроби равны" << endl; }
}

rational& rational::operator+(const rational& r) {
	rational temp;
	int t_a, t_b;
	t_b = this->b * r.b;
	t_a = this->a * r.b + this->b * r.a;
	temp.set(t_a, t_b);
	return temp;
}

rational& rational::operator++() {
	this->a += 1;
	return *this;
}

rational& rational::operator++(int value) {
	rational temp(this->a, this->b);
	this->a += 1;
	return temp;
}