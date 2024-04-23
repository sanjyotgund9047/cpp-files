/*Write the definition for a class Cylinder that contains data members radius and height. The class
has the following member functions:
a. void setradius(float) to set the radius of data member.
b. void setheight(float) to set the height of data member.
c. float volume( ) to calculate and return the volume of the cylinder.
Write a C++ program to create cylinder object and display its volume*/
#include <iostream>
using namespace std;
class Cylinder {
private:
    float radius;
    float height;

public:
    void setRadius(float r) {
        radius = r;
    }

    void setHeight(float h) {
        height = h;
    }

    float volume() {
        return 3.14159 * radius * radius * height;
    }
};

int main() {
    // Create an instance of the Cylinder class
    Cylinder myCylinder;

    // Set radius and height
    myCylinder.setRadius(3.0);
    myCylinder.setHeight(5.0);

    // Calculate and display volume
    std::cout << "Volume of the cylinder: " << myCylinder.volume() << std::endl;

    return 0;

/*Output:-
Volume of the cylinder: 141.372
*/
}