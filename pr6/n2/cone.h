#pragma once
#include <iostream>
using namespace std;
class Cone {
protected:
    const double PI = 3.14159265;
public:
    double r, h;
    Cone(double r=0, double h=0);
    virtual double surface();
    virtual double volume();
    friend istream& operator>>(istream& in, Cone& c);
    friend ostream& operator<<(ostream& out, Cone& c);
};

class TruncatedCone : public Cone {
public:
    double R;
    TruncatedCone(double r=0, double R=0, double h=0);
    double surface();
    double volume();
    friend istream& operator>>(istream& in, TruncatedCone& c);
    friend ostream& operator<<(ostream& out, TruncatedCone& c);
    bool operator==(TruncatedCone& T);
    bool operator!=(TruncatedCone& T);
};