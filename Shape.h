#pragma once

#include <iostream>
using namespace std;

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}

    virtual void displayShape() const = 0;
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};