#include "Shape.h"
#include "Triangle.h"
#include <iostream>
#include <cmath>
using namespace std;

Triangle::Triangle(double a, double b, double c) : A(a), B(b), C(c)
{
    cout << "Triangle created successfully!" << endl;
}

void Triangle::displayShape() const
{
    cout << "Triangle" << endl;
}

double Triangle::Area() const
{
    double s = (A + B + C) / 2;
    return sqrt(s * (s - A) * (s - B) * (s - C));
}

double Triangle::Perimeter() const
{
    return (A + B + C);
}
