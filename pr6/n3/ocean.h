#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ocean {
protected:
    string name;
    double depth;
    long long int surface_area;

public:
    Ocean();

    Ocean(string n, double d, long long int a);

    string getName();
    double getDepth();
    long long int getSurface_area();

    friend ostream& operator<<(ostream& os, const Ocean& ocean);
    friend istream& operator>>(istream& is, Ocean& ocean);
};
