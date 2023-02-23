#include "figure.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

figure::figure() :x1(0), x2(0), x3(0), x4(0), y1(0), y2(0), y3(0), y4(0), S(0), P(0) {};

figure::figure(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4) :x1(x1), x2(x2), x3(x3), x4(x4), y1(y1), y2(y2), y3(y3), y4(y4) {
	S = 0.5 * sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2)) * sqrt(pow((x4 - x2), 2) + pow((y4 - y2), 2)) * (sqrt(1-pow((((x3-x1)*(x4-x2)+(y3-y1)*(y4-y2))/(sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2)) * sqrt(pow((x4 - x2), 2) + pow((y4 - y2), 2)))), 2)));
	P = sqrt(pow((x2-x1), 2)+pow((y2 - y1),2)) + sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2)) + sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2)) + sqrt(pow((x1 - x4), 2) + pow((y1 - y4), 2));
};

void figure::show() {
	cout << "сторона 1: "<<sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))<<endl;
	cout << "сторона 2: "<<sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3))<<endl;
	cout << "сторона 3: "<<sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4))<<endl;
	cout << "сторона 4: "<<sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4- y1))<<endl;
	cout << "площадь: " << S << endl;
	cout << "периметр: " << P << endl;
};

bool figure::is_prug() {
	float a1, a2, b1, b2, c1, c2, d1, d2;
	a1 = x2 - x1;
	a2 = y2 - y1;
	b1 = x3 - x2;
	b2 = y3 - y2;
	c1 = x4 - x3;
	c2 = y4 - y3;
	d1 = x1 - x4;
	d2 = y1 - y4;
	
	return ((a1 * b1 + a2 * b2) == 0) and ((c1 * b1 + c2 * b2) == 0) and ((a1 * d1 + a2 * d2) == 0);
};

bool figure::is_romb() {
	float a, b, c, d;
	a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	c = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
	d = sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1));
	return a == b and b == c and c == d;
};

bool figure::is_square() {
	return figure::is_prug() and figure::is_romb();
};

bool figure::is_in_circle() {
	float a1, a2, b1, b2, c1, c2, d1, d2;
	float A, cosA, B, cosB;
	a1 = x2 - x1;
	a2 = y2 - y1;
	b1 = x3 - x2;
	b2 = y3 - y2;
	c1 = x4 - x3;
	c2 = y4 - y3;
	d1 = x1 - x4;
	d2 = y1 - y4;
	cosA = (a1 * b1 + a2 * b2) / sqrt(a1 * a1 + a2 * a2) / sqrt(b1 * b1 + b2 * b2);
	A = acos(cosA);
	A = int(A * 100);

	cosB = (c1 * d1 + c2 * d2) / sqrt(c1 * c1 + c2 * c2) / sqrt(d1 * d1 + d2 * d2);
	B = acos(cosB);
	B = int(B * 100);
	return A + B == 314;
};

bool figure::is_out_circle() {
	float a, b, c, d;
	a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	c = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
	d = sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1));
	return b + d == a + c;
};
