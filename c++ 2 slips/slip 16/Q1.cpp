/*Write a C++ program to create a class Number which contains two integer data members. Create
and initialize the object by using default constructor, parameterized constructor. Write a
member function to display maximum from given two numbers for all objects.*/

#include <iostream>

using namespace std;

class Number {
private:
    int num1;
    int num2;

public:
    // Default constructor
    Number() : num1(0), num2(0) {}

    // Parameterized constructor
    Number(int n1, int n2) : num1(n1), num2(n2) {}

    // Member function to display maximum of the two numbers
    void displayMax() {
        cout << "Maximum of " << num1 << " and " << num2 << " is: " << max(num1, num2) << endl;
    }
};

int main() {
    // Default constructor
    Number num1_default;
    cout << "Default Constructor:" << endl;
    num1_default.displayMax();
    cout << endl;

    // Parameterized constructor
    Number num2_param(10, 20);
    cout << "Parameterized Constructor:" << endl;
    num2_param.displayMax();
    cout << endl;

    return 0;
}

/*Output:-
Default Constructor:
Maximum of 0 and 0 is: 0

Parameterized Constructor:
Maximum of 10 and 20 is: 20
*/