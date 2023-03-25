#pragma once
#include <iostream>
using namespace std;
class cone
{
    const double pi = 3.14159265;
    double x, y, z;        
    double radius;         
    double height;         
public:
    cone();
    cone(double r, double h);
    cone(double a, double b, double c, double r, double h);
    void setCoordinate(double a, double b, double c);
    void setRadius(double r);
    void setHeight(double h);
    double getRadius();
    double getHeight();
    double area();
    double volume();

    friend ostream& operator<<(ostream& out, cone obj);
};

