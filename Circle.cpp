#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(double r) : radius(r)
{
    cout << "Circle created successfully!" << endl;
}

void Circle::displayShape() const
{
    cout << "Circle" << endl;
}

double Circle::Area() const
{
    return M_PI * radius * radius;
}

double Circle::Perimeter() const
{
    return 2 * M_PI * radius;
}
