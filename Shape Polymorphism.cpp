/*
==========================================================
Title: Shape Polymorphism System in C++
Author: NJI HALLE CHO NKWENTI
Date: 2026
Description:
This program demonstrates the use of abstraction and 
polymorphism in C++ using a graphics editor scenario.

- An abstract base class 'Shape' defines a common interface
  for all shapes with pure virtual methods:
    • calculateArea()
    • display()

- Derived classes 'Circle' and 'Rectangle' implement
  their own versions of these methods.

- Runtime polymorphism is demonstrated using base class
  pointers to invoke methods of derived classes.

Concepts Used:
✔ Abstraction (Abstract Class, Pure Virtual Functions)
✔ Inheritance
✔ Runtime Polymorphism (Function Overriding)
✔ Encapsulation

==========================================================
*/

#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual double calculateArea() = 0;
    virtual void display() = 0;
    virtual ~Shape() {}
};

// Derived Class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double calculateArea() override {
        return 3.1416 * radius * radius;
    }

    void display() override {
        cout << "Circle:" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << calculateArea() << endl;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() override {
        return length * width;
    }

    void display() override {
        cout << "Rectangle:" << endl;
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << calculateArea() << endl;
    }
};

// Main function
int main() {
    Shape* shape1;
    Shape* shape2;

    Circle c(5.0);
    Rectangle r(4.0, 6.0);

    shape1 = &c;
    shape2 = &r;

    shape1->display();
    cout << endl;
    shape2->display();

    return 0;
}