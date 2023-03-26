#pragma once
#include <iostream>
#include <string>
#include "ocean.h"
#include "sea.h"

using namespace std;

class Bay : public Sea {
private:
    string seaName;
public:
    Bay();
    Bay(string n, string l, double d, long long int a,
        int t, int sa, string nsea);

    string getSeaName();

    friend ostream& operator<<(ostream& os, const Bay& bay);
    friend istream& operator>>(istream& is, Bay& bay);
};
