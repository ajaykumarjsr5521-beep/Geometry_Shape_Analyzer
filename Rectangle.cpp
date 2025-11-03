#include "Rectangle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(double l, double b) : l(l), b(b)
{
    cout << "Rectangle created successfully!" << endl;
}

void Rectangle::displayShape() const
{
    cout << "Rectangle" << endl;
}

double Rectangle::Area() const
{
    return l * b;
}

double Rectangle::Perimeter() const
{
    return 2 * (l + b);
}
