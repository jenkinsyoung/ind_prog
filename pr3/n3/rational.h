#pragma once
class rational
{
	friend rational operator-(rational& r1, rational& r2);
private:
	int a, b;
public:
	rational();
	~rational();
	rational(int a1, int b1);
	void set(int a1, int b1);
	void show();
	int get_a();
	int get_b();
	rational& operator+ (const rational& r);
	rational& operator= (const rational& r);
	bool operator== (const rational& r);
	void operator> (const rational& r);
	rational& operator++();
	rational& operator++(int value);
};