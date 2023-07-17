// Aritra Bandyopadhyay 2021CSB107
// Assignment 4_4

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

// ShapeStack class for storing shapes
class ShapeStack {
private:
    vector<Shape*> stack;
public:
    void Push(Shape* shape) {
        stack.push_back(shape);
    }

    void Pop() {
        if (!stack.empty()) {
            delete stack.back();
            stack.pop_back();
        }
    }

    void Display() const {
        for (const auto& shape : stack) {
            cout << "Shape area: " << shape->area() << endl;
        }
    }

    double TotalAreaCovered() const {
        double totalArea = 0;
        for (const auto& shape : stack) {
            totalArea += shape->area();
        }
        return totalArea;
    }

    ~ShapeStack() {
        for (const auto& shape : stack) {
            delete shape;
        }
    }
};

int main() {
    // create ShapeStack object and add different shapes
    ShapeStack stack;
    stack.Push(new Triangle(4, 6));
    stack.Push(new Rectangle(5, 8));
    stack.Push(new Circle(3));
    stack.Push(new Triangle(2.5, 4));
    stack.Push(new Rectangle(6, 9.5));
    stack.Push(new Circle(4.5));

    double sum = stack.TotalAreaCovered();
    cout << "Total Area covered: " << sum << endl;

       
}