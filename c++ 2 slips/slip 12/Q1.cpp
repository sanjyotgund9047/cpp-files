/*Write a C++ program to accept length and width of a rectangle. Calculate and display perimeter
as well as area of a rectangle by using inline function.*/

#include <iostream>

using namespace std;

// Inline function to calculate perimeter of a rectangle
inline double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Inline function to calculate area of a rectangle
inline double calculateArea(double length, double width) {
    return length * width;
}

int main() {
    double length, width;

    // Accept length and width of the rectangle
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Calculate perimeter and area using inline functions
    double perimeter = calculatePerimeter(length, width);
    double area = calculateArea(length, width);

    // Display the results
    cout << "Perimeter of the rectangle: " << perimeter << endl;
    cout << "Area of the rectangle: " << area << endl;

    return 0;
}

/*Output:-
Enter the length of the rectangle: 5
Enter the width of the rectangle: 3
Perimeter of the rectangle: 16
Area of the rectangle: 15
*/