/*Write a C++ program to read two float numbers. Perform arithmetic binary operations +,-,*,/ on
these numbers using inline function. Display the resultant value*/

#include <iostream>

using namespace std;

// Inline function for addition
inline float add(float a, float b) {
    return a + b;
}

// Inline function for subtraction
inline float subtract(float a, float b) {
    return a - b;
}

// Inline function for multiplication
inline float multiply(float a, float b) {
    return a * b;
}

// Inline function for division
inline float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        cerr << "Error: Division by zero!" << endl;
        return 0; // Return 0 if division by zero
    }
}

int main() {
    float num1, num2;

    // Input two float numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Perform arithmetic operations using inline functions
    cout << "Addition result: " << add(num1, num2) << endl;
    cout << "Subtraction result: " << subtract(num1, num2) << endl;
    cout << "Multiplication result: " << multiply(num1, num2) << endl;
    cout << "Division result: " << divide(num1, num2) << endl;

    return 0;
}

/*Output:-
Enter the first number: 10
Enter the second number: 3
Addition result: 13
Subtraction result: 7
Multiplication result: 30
Division result: 3.33333
*/