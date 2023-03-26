#include "cone.h"
#include <iostream>

using namespace std;

Cone::Cone(double r, double h) {
    this->r = r;
    this->h = h;
}

double Cone::surface() {
    double l = sqrt(r * r + h * h);
    return PI * r * (r + l);
}

double Cone::volume() {
    return PI * r * r * h / 3;
}

istream& operator>>(istream& in, Cone& c) {
    in >> c.r >> c.h;
    return in;
}

ostream& operator<<(ostream& out, Cone& c) {
    out << "r = " << c.r << ", h = " << c.h;
    return out;
}

TruncatedCone::TruncatedCone(double r, double R, double h) : Cone(r, h) {
    this->R = R;
}

double TruncatedCone::surface() {
    double l1 = sqrt(r * r + h * h);
    double l2 = sqrt(R * R + h * h);
    return PI * (r + R) * l1 + PI * r * r + PI * R * R;
}

double TruncatedCone::volume() {
    return PI * h * (r * r + r * R + R * R) / 3;
}

bool TruncatedCone::operator==(TruncatedCone& T) {
    return r == T.r && R == T.R && h == T.h;
}

bool TruncatedCone::operator!=(TruncatedCone& T) {
    return !(*this == T);
}
