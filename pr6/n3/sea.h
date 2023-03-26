#pragma once
#include <iostream>
#include <string>
#include "ocean.h"

using namespace std;

class Sea : public Ocean {
protected:
    string location;
    int temperature;
    int saltiness;

public:
    Sea();
    Sea(string n, string l, double d, long long int a, int t, int sa);

    string getLocation();

    int getTemperature();

    int getSaltiness();

    friend ostream& operator<<(ostream& os, const Sea& sea);

    friend istream& operator>>(istream& is, Sea& sea);
};
