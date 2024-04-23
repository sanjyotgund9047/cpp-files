/*Write a C++ program to design a class complex to represent complex number. The complex class
uses an external function (as a friend function) to add two complex number. The function should
return an object of type complex representing the sum of two complex Numbers. */
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend function to add two complex numbers
    friend Complex add(const Complex& c1, const Complex& c2);

    // Function to display the complex number
    void display() const {
        std::cout << "(" << real << " + " << imag << "i)" << std::endl;
    }
};

// Friend function definition to add two complex numbers
Complex add(const Complex& c1, const Complex& c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

int main() {
    // Define two complex numbers
    Complex num1(3.0, 4.0);
    Complex num2(2.0, -1.0);

    // Add two complex numbers using the friend function
    Complex sum = add(num1, num2);

    // Display the result
    std::cout << "Sum of complex numbers: ";
    sum.display();

    return 0;
}

/*Output
Sum of complex numbers: (5 + 3i)
*/