#include "circle.h"
#include <iostream>

using namespace std;

circle::circle() : radius(0), x_center(0), y_center(0) {};

circle::circle(float r, float x, float y): radius(r), x_center(x), y_center(y) {};

void circle::set_circle(float r, float x, float y) {
	radius = r;
	x_center = x;
	y_center = y;
};

float circle::square() {
	const float pi = 3.14159;
	return pi * radius * radius;
};

bool circle::triangle_around(float a, float b, float c) {
	float cosA;
	cosA = (b * b + c * c - a * a) / (2 * b * c);
	float sinA = sqrt(1 - cosA * cosA);
	return a / sinA == 2 * radius * radius;
};
bool circle::triangle_in(float a, float b, float c) {
	float p = (a + b + c) / 2;
	float s1 = sqrt(p * (p - a) * (p - b) * (p - c));
	float s2 = p * radius;
	return s1 == s2;
};
bool circle::check_circle(float r, float x_cntr, float y_cntr) {
	float o1o2 = sqrt((x_center - x_cntr) * (x_center - x_cntr) + (y_center - y_cntr) * (y_center - y_cntr));
	float r_max = max(r, radius);
	float r_min = min(r, radius);
	if (r_max > o1o2) {
		return r_max - r_min < o1o2;
	} else return r + radius > o1o2;
};