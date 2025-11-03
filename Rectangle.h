#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
    double l, b;

public:
    Rectangle(double l, double b);
    ~Rectangle() {}

    void displayShape() const override;
    double Area() const override;
    double Perimeter() const override;
};


