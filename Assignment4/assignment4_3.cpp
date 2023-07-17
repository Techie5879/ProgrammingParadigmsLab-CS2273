// Aritra Bandyopadhyay 2021CSB107
// Assignment 4_3

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Shape class (base class)
class Shape {
public:
    virtual double area() const = 0; // pure virtual function
    virtual ~Shape() {} // virtual destructor
};

// Triangle class (derived from Shape class)
class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle() : base(0), height(0) {} // default constructor
    Triangle(double b, double h) : base(b), height(h) {} // overloaded constructor
    Triangle(const Triangle& other) : base(other.base), height(other.height) {} // copy constructor
    Triangle& operator=(const Triangle& other) { // assignment operator
        if (this != &other) {
            base = other.base;
            height = other.height;
        }
        return *this;
    }
    double area() const override { // overridden area function
        return 0.5 * base * height;
    }
};

// Rectangle class (derived from Shape class)
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle() : length(0), width(0) {} // default constructor
    Rectangle(double l, double w) : length(l), width(w) {} // overloaded constructor
    Rectangle(const Rectangle& other) : length(other.length), width(other.width) {} // copy constructor
    Rectangle& operator=(const Rectangle& other) { // assignment operator
        if (this != &other) {
            length = other.length;
            width = other.width;
        }
        return *this;
    }
    double area() const override { // overridden area function
        return length * width;
    }
};

// Circle class (derived from Shape class)
class Circle : public Shape {
private:
    double radius;
public:
    Circle() : radius(0) {} // default constructor
    Circle(double r) : radius(r) {} // overloaded constructor
    Circle(const Circle& other) : radius(other.radius) {} // copy constructor
    Circle& operator=(const Circle& other) { // assignment operator
        if (this != &other) {
            radius = other.radius;
        }
        return *this;
    }
    double area() const override { // overridden area function
        return M_PI * pow(radius, 2);
    }
};

// SumArea function to calculate total area of shapes
double SumArea(const vector<Shape*>& shapes) {
    double totalArea = 0;
    for (const auto& shape : shapes) {
        totalArea += shape->area();
    }
    return totalArea;
}

int main() {
    // create vector of Shape pointers and add different shapes
    vector<Shape*> shapes;
    shapes.push_back(new Triangle(4, 6));
    shapes.push_back(new Rectangle(5, 8));
    shapes.push_back(new Circle(3));
    shapes.push_back(new Triangle(2.5, 4));
    shapes.push_back(new Rectangle(6, 9.5));
    shapes.push_back(new Circle(4.5));

    // calculate total area of shapes and display result
    double totalArea = SumArea(shapes);
    cout << "Total area covered by shapes: " << totalArea << endl;

    // free allocated memory for Shape objects
    for (const auto& shape : shapes) {
        delete shape;
    }

    // // create some shapes
    // Triangle t1(3, 4);
    // Rectangle r1(2, 5);
    // Circle c1(6);

    // // copy them using copy constructors
    // Triangle t2 = t1;
    // Rectangle r2 = r1;
    // Circle c2 = c1;

    // // assign them to new objects using assignment operators
    // Triangle t3;
    // t3 = t2;
    // Rectangle r3;
    // r3 = r2;
    // Circle c3;
    // c3 = c2;

    // // modify the original shapes
    // t1 = Triangle(5, 6);
    // r1 = Rectangle(3, 7);
    // c1 = Circle(8);

    // // print the areas of the shapes
    // cout << "Triangle t1 area: " << t1.area() << endl;
    // cout << "Rectangle r1 area: " << r1.area() << endl;
    // cout << "Circle c1 area: " << c1.area() << endl;

    // cout << "Triangle t2 area: " << t2.area() << endl;
    // cout << "Rectangle r2 area: " << r2.area() << endl;
    // cout << "Circle c2 area: " << c2.area() << endl;

    // cout << "Triangle t3 area: " << t3.area() << endl;
    // cout << "Rectangle r3 area: " << r3.area() << endl;
    // cout << "Circle c3 area: " << c3.area() << endl;

    return 0;
}
