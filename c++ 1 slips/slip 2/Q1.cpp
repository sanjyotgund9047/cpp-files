/*Write a C++ program to create two classes Rectangle1 and Rectangle2. Compare area of both the
rectangles using friend function.*/
#include <iostream>

class Rectangle2; // Forward declaration

class Rectangle1 {
private:
    float length;
    float width;

public:
    Rectangle1(float l, float w) : length(l), width(w) {}

    // Friend function to compare areas of Rectangle1 and Rectangle2
    friend void compareAreas(const Rectangle1& r1, const Rectangle2& r2);

    float area() const {
        return length * width;
    }
};

class Rectangle2 {
private:
    float length;
    float width;

public:
    Rectangle2(float l, float w) : length(l), width(w) {}

    // Friend function to compare areas of Rectangle1 and Rectangle2
    friend void compareAreas(const Rectangle1& r1, const Rectangle2& r2);

    float area() const {
        return length * width;
    }
};

// Friend function definition to compare areas of Rectangle1 and Rectangle2
void compareAreas(const Rectangle1& r1, const Rectangle2& r2) {
    float area1 = r1.area();
    float area2 = r2.area();

    if (area1 > area2) {
        std::cout << "Area of Rectangle1 is greater than Area of Rectangle2" << std::endl;
    } else if (area1 < area2) {
        std::cout << "Area of Rectangle2 is greater than Area of Rectangle1" << std::endl;
    } else {
        std::cout << "Area of Rectangle1 is equal to Area of Rectangle2" << std::endl;
    }
}

int main() {
    Rectangle1 rect1(4.0, 5.0);
    Rectangle2 rect2(3.0, 6.0);

    compareAreas(rect1, rect2);

    return 0;
}
