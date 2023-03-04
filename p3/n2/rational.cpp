#include "rational.h"
#include <iostream>

using namespace std;

rational::rational() :a(0), b(1) {};

rational::rational(int a1, int b1){
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