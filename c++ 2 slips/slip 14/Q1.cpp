/*Write a C++ program to interchange values of two integer numbers (use call by reference)*/
#include <iostream>

// Function to interchange values using call by reference
void interchange(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1, num2;

    // Input two integer numbers
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;

    // Output original values
    std::cout << "Before interchange:" << std::endl;
    std::cout << "First number: " << num1 << std::endl;
    std::cout << "Second number: " << num2 << std::endl;

    // Call interchange function
    interchange(num1, num2);

    // Output values after interchange
    std::cout << "After interchange:" << std::endl;
    std::cout << "First number: " << num1 << std::endl;
    std::cout << "Second number: " << num2 << std::endl;

    return 0;
}
/*Output:-
Enter first number: 10
Enter second number: 20
Before interchange:
First number: 10
Second number: 20
After interchange:
First number: 20
Second number: 10
*/