/*Write a C++ program to print area of circle, square and rectangle using inline function.*/
#include <iostream>

// Inline function to calculate the area of a circle
inline float areaCircle(float radius) {
    return 3.14159 * radius * radius;
}

// Inline function to calculate the area of a square
inline float areaSquare(float side) {
    return side * side;
}

// Inline function to calculate the area of a rectangle
inline float areaRectangle(float length, float width) {
    return length * width;
}

int main() {
    float radius, side, length, width;

    // Input for circle
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "Area of the circle: " << areaCircle(radius) << std::endl;

    // Input for square
    std::cout << "Enter the side length of the square: ";
    std::cin >> side;
    std::cout << "Area of the square: " << areaSquare(side) << std::endl;

    // Input for rectangle
    std::cout << "Enter the length of the rectangle: ";
    std::cin >> length;
    std::cout << "Enter the width of the rectangle: ";
    std::cin >> width;
    std::cout << "Area of the rectangle: " << areaRectangle(length, width) << std::endl;

    return 0;
}

/*
Output
Enter the radius of the circle: 2
Area of the circle: 12.5664
Enter the side length of the square: 3 
Area of the square: 9
Enter the length of the rectangle: 4
Enter the width of the rectangle: 4
Area of the rectangle: 16
*/