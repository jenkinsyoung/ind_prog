#include <iostream>
using namespace std;

template <class T> void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

struct Struct {
	int a;
	double b;
};

class Class {
	int value;
public:
	Class(int value) : value(value) {}
	void print() {
		cout << "Value = " << value << endl;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	int x = 5, y = 10;
	double d1 = 3.5, d2 = 6.9;
	Struct s1 = { 1, 2.5 }, s2 = { 3, 4.8 };
	Class obj1(20), obj2(30);
	cout << "Перед обменом: " << endl;
	cout << "x = " << x << ", y = " << y << endl;
	cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
	cout << "Struct s1 = {" << s1.a << ", " << s1.b << "}, s2 = {" << s2.a << ", " << s2.b << "}" << endl;
	cout << "obj1: ";
	obj1.print();
	cout << "obj2: ";
	obj2.print();
	cout << endl;

	Swap(x, y);
	Swap(d1, d2);
	Swap(s1, s2);
	Swap(obj1, obj2);

	cout << "После обмена: " << endl;
	cout << "x = " << x << ", y = " << y << endl;
	cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
	cout << "MyStruct s1 = {" << s1.a << ", " << s1.b << "}, s2 = {" << s2.a << ", " << s2.b << "}" << endl;
	cout << "obj1: ";
	obj1.print();
	cout << "obj2: ";
	obj2.print();

	return 0;
}