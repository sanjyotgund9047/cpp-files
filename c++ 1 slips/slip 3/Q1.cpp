/*Write a C++ program to overload function Volume and find Volume of Cube, Cylinder and
Sphere. */
#include <iostream>
#include <cmath>

class VolumeCalculator {
public:
    // Function to calculate the volume of a cube
    double Volume(double side) {
        return side * side * side;
    }

    // Function to calculate the volume of a cylinder
    double Volume(double radius, double height) {
        return M_PI * radius * radius * height;
    }

    // Function to calculate the volume of a sphere
    double VolumeSphere(double radius) {
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }
};

int main() {
    VolumeCalculator calculator;

    // Calculate and display the volume of a cube with side length 3
    double cubeVolume = calculator.Volume(3.0);
    std::cout << "Volume of Cube: " << cubeVolume << std::endl;

    // Calculate and display the volume of a cylinder with radius 2 and height 4
    double cylinderVolume = calculator.Volume(2.0, 4.0);
    std::cout << "Volume of Cylinder: " << cylinderVolume << std::endl;

    // Calculate and display the volume of a sphere with radius 3
    double sphereVolume = calculator.VolumeSphere(3.0);
    std::cout << "Volume of Sphere: " << sphereVolume << std::endl;

    return 0;
}

/*
Output:-
Volume of Cube: 27
Volume of Cylinder: 50.2655
Volume of Sphere: 113.097
*/