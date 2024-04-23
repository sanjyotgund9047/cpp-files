/*Write a C++ program to create a class Array that contains one float array as member. Overload
the Unary ++ and -- operators to increase or decrease the value of each element of an array. Use
friend function for operator function.*/
#include <iostream>

const int SIZE = 5; // Size of the array

class Array {
private:
    float arr[SIZE]; // Array to hold float values

public:
    Array() { // Constructor to initialize array elements to 0
        for (int i = 0; i < SIZE; ++i) {
            arr[i] = 0.0;
        }
    }

    // Friend function to overload ++ operator
    friend Array& operator++(Array& arrObj);

    // Friend function to overload -- operator
    friend Array& operator--(Array& arrObj);

    // Function to display array elements
    void display() {
        for (int i = 0; i < SIZE; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Overloading ++ operator as friend function
Array& operator++(Array& arrObj) {
    for (int i = 0; i < SIZE; ++i) {
        ++arrObj.arr[i];
    }
    return arrObj;
}

// Overloading -- operator as friend function
Array& operator--(Array& arrObj) {
    for (int i = 0; i < SIZE; ++i) {
        --arrObj.arr[i];
    }
    return arrObj;
}

int main() {
    Array myArray;

    std::cout << "Original array: ";
    myArray.display();

    ++myArray;
    std::cout << "Array after increment: ";
    myArray.display();

    --myArray;
    std::cout << "Array after decrement: ";
    myArray.display();

    return 0;
}
/*
output:-
Original array: 0 0 0 0 0 
Array after increment: 1 1 1 1 1
Array after decrement: 0 0 0 0 0
*/