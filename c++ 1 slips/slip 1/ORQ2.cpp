/* Write a C++ program to create a class Shape with functions to find area of the shape and display
the name of the shape and other essential components of the class. Create derived classes circle,
rectangle and trapezoid each having overridden function area and display. Write a suitable
program to illustrate Virtual Function.*/
#include <iostream>
#include <string>

class Shape {
protected:
    std::string name;

public:
    Shape(const std::string& n) : name(n) {}

    // Virtual destructor
    virtual ~Shape() {}

    // Virtual function to calculate area
    virtual float area() const = 0;

    // Virtual function to display shape details
    virtual void display() const {
        std::cout << "Shape: " << name << std::endl;
    }
};


class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : Shape("Circle"), radius(r) {}

    // Override area calculation for circle
    float area() const override {
        return 3.14159 * radius * radius;
    }

    // Override display to include radius
    void display() const override {
        Shape::display();
        std::cout << "Radius: " << radius << std::endl;
    }
};

class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l, float w) : Shape("Rectangle"), length(l), width(w) {}

    // Override area calculation for rectangle
    float area() const override {
        return length * width;
    }

    // Override display to include length and width
    void display() const override {
        Shape::display();
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
    }
};

class Trapezoid : public Shape {
private:
    float base1, base2, height;

public:
    Trapezoid(float b1, float b2, float h) : Shape("Trapezoid"), base1(b1), base2(b2), height(h) {}

    // Override area calculation for trapezoid
    float area() const override {
        return 0.5 * (base1 + base2) * height;
    }

    // Override display to include base1, base2, and height
    void display() const override {
        Shape::display();
        std::cout << "Base1: " << base1 << ", Base2: " << base2 << ", Height: " << height << std::endl;
    }
};

int main() {
    // Create instances of different shapes
    Shape* shapes[3];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Trapezoid(3.0, 5.0, 4.0);

    // Display details and areas of all shapes
    for (int i = 0; i < 3; ++i) {
        shapes[i]->display();
        std::cout << "Area: " << shapes[i]->area() << std::endl;
        std::cout << std::endl;
    }

    // Cleanup
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}

/*Output
Shape: Circle
Radius: 5
Area: 78.5397

Shape: Rectangle
Length: 4, Width: 6
Area: 24

Shape: Trapezoid
Base1: 3, Base2: 5, Height: 4
Area: 16
*/