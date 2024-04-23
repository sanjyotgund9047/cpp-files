/*Write a C++ program using class which contains two data members as type integer. Create and
initialize the objects using default constructor, parameterized constructor with default value.
Write a member function to display maximum from given two numbers for all objects.*/
#include <iostream>

class Numbers {
private:
    int num1;
    int num2;

public:
    // Default constructor
    Numbers() : num1(0), num2(0) {}

    // Parameterized constructor with default values
    Numbers(int n1, int n2 = 0) : num1(n1), num2(n2) {}

    // Function to display maximum of the two numbers
    void displayMax() const {
        int max = (num1 > num2) ? num1 : num2;
        std::cout << "Maximum of " << num1 << " and " << num2 << " is: " << max << std::endl;
    }
};

int main() {
    // Create objects using default constructor and display maximum
    Numbers obj1;
    std::cout << "Using default constructor:" << std::endl;
    obj1.displayMax();

    // Create objects using parameterized constructor with default values and display maximum
    Numbers obj2(5);
    Numbers obj3(3, 7);
    std::cout << "\nUsing parameterized constructor with default values:" << std::endl;
    obj2.displayMax();
    obj3.displayMax();

    return 0;
}

/*Output
Using default constructor:
Maximum of 0 and 0 is: 0

Using parameterized constructor with default values:
Maximum of 5 and 0 is: 5
Maximum of 3 and 7 is: 7

*/