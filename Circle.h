#pragma once

#include "Shape.h"
#define M_PI 3.14

class Circle : public Shape
{
    double radius;

public:
    Circle(double r);
    ~Circle() {}

    void displayShape() const override;
    double Area() const override;
    double Perimeter() const override;
};


