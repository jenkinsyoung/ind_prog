#include "bay.h"
#include <iostream>
#include <string>
#include "sea.h"
#include "ocean.h"

using namespace std;


Bay::Bay() : Sea() {
    seaName = "unspecified";
}

Bay::Bay(string n, string l, double d, long long int a,
    int t, int sa, string nsea)
    : Sea(n, l, d, a, t, sa) {
    seaName = nsea;
}
string Bay::getSeaName() {
    return seaName;
}

ostream& operator<<(ostream& os, const Bay& bay) {
    os << static_cast<const Sea&>(bay);
    os << "Sea name: " << bay.seaName << std::endl;

    return os;
}

istream& operator>>(istream& is, Bay& bay) {
    cout << "Name: ";
    cin>> bay.name;

    cout << "Location: ";
    cin >> bay.location;

    cout << "Depth (m): ";
    is >> bay.depth;

    cout << "Surface area (sq km): ";
    is >> bay.surface_area;

    cout << "Temperature (C): ";
    is >> bay.temperature;

    cout << "Saltiness (ppt): ";
    is >> bay.saltiness;

    cout << "Sea Name: ";
    cin>> bay.seaName;

    return is;
}
