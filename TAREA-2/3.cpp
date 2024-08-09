#include <iostream>
#include <cmath>

using namespace std;

class GeometricFigure {
public:
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Triangle : public GeometricFigure {
public:
    double base, height, side1, side2, side3;

    Triangle(double _base, double _height, double _side1, double _side2, double _side3) {
        base = _base;
        height = _height;
        side1 = _side1;
        side2 = _side2;
        side3 = _side3;
    }

    double calculateArea() override {
        return 0.5 * base * height;
    }

    double calculatePerimeter() override {
        return side1 + side2 + side3;
    }
};

class Square : public GeometricFigure {
public:
    double side;

    Square(double _side) {
        side = _side;
    }

    double calculateArea() override {
        return side * side;
    }

    double calculatePerimeter() override {
        return 4 * side;
    }
};

class Circle : public GeometricFigure {
public:
    double radius;

    Circle(double _radius) {
        radius = _radius;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius;
    }
};

int main() {
    Triangle triangle(3.0, 4.0, 3.0, 4.0, 5.0);
    cout << "Triangle Area: " << triangle.calculateArea() << ", Perimeter: " << triangle.calculatePerimeter() << endl;

    Square square(4.0);
    cout << "Square Area: " << square.calculateArea() << ", Perimeter: " << square.calculatePerimeter() << endl;

    Circle circle(5.0);
    cout << "Circle Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << endl;

    return 0;
}
