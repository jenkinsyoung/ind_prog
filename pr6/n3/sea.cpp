#include "sea.h"
#include <iostream>
#include <string>
#include "ocean.h"

using namespace std;

Sea::Sea() : Ocean() {
    location = "unspecified";
    temperature = 0;
    saltiness = 0;
}

Sea::Sea(std::string n, std::string l, double d, long long int a, int t, int sa)
    : Ocean(n, d, a) {
    location = l;
    temperature = t;
    saltiness = sa;
}

string Sea::getLocation() {
    return location;
}

int Sea::getTemperature() {
    return temperature;
}

int Sea::getSaltiness() {
    return saltiness;
}

ostream& operator<<(ostream& os, const Sea& sea) {
    os << static_cast<const Ocean&>(sea);
    os << "Location: " << sea.location << endl;
    os << "Temperature: " << sea.temperature << " C" << std::endl
        << "Saltiness: " << sea.saltiness << " ppt" << std::endl;

    return os;
}

istream& operator>>(istream& is, Sea& sea){
    cout << "Name: ";
    cin >> sea.name;

    cout << "Location: ";
    cin >> sea.location;

    cout << "Depth (m): ";
    is >> sea.depth;

    cout << "Surface area (sq km): ";
    is >> sea.surface_area; ;
   
    cout << "Temperature (C): ";
    is >> sea.temperature;

    cout << "Saltiness (ppt): ";
    is >> sea.saltiness;

    return is;
}