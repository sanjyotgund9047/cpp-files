/*Write a C++ program to check minimum and maximum of two integer number (use inline
function and conditional operator) */

#include <iostream>

using namespace std;

// Inline function to find minimum of two numbers
inline int min(int a, int b) {
    return (a < b) ? a : b;
}

// Inline function to find maximum of two numbers
inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int num1, num2;

    // Input two integer numbers
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Find and display minimum and maximum
    cout << "Minimum of " << num1 << " and " << num2 << " is: " << min(num1, num2) << endl;
    cout << "Maximum of " << num1 << " and " << num2 << " is: " << max(num1, num2) << endl;

    return 0;
}

/*Output:-
Enter first number: 20
Enter second number: 10
Minimum of 20 and 10 is: 10
Maximum of 20 and 10 is: 20
*/