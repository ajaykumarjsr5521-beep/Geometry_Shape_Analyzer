#pragma once

class Triangle : public Shape
{
    double A, B, C;

public:
    Triangle(double a, double b, double c);
    ~Triangle() {}

    void displayShape() const override;
    double Area() const override;
    double Perimeter() const override;
};


