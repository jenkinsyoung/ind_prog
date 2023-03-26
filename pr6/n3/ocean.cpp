#include "ocean.h"
#include <iostream>
#include <string>

using namespace std;

Ocean::Ocean() {
    name = "unspecified";
    depth = 0;
    surface_area = 0;
}

Ocean::Ocean(string n, double d, long long int a) {
    name = n;
    depth = d;
    surface_area = a;
}

string Ocean::getName() {
    return name;
}

double Ocean::getDepth() {
    return depth;
}
long long int Ocean::getSurface_area() {
    return surface_area;
}

ostream& operator<<(ostream& os, const Ocean& ocean) {
    os << "Name: " << ocean.name << std::endl
        << "Depth: " << ocean.depth << " m" << std::endl
        << "Surface area: " << ocean.surface_area << " sq km" << std::endl;

    return os;
}

istream& operator>>(istream& is, Ocean& ocean) {
    cout << "Name: ";
    cin>>ocean.name;

    cout << "Depth (m): ";
    is >> ocean.depth;

    cout << "Surface area (sq km): ";
    is >> ocean.surface_area;

    return is;
}
