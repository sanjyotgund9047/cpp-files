/*Write a C++ program to implement a class printdata to overload print function as follows:
void print(int) - outputs value followed by the value of the integer.
Eg. print(10) outputs - value 10
void print(char *) – outputs value followed by the string in double quotes.
Eg. print(“hi”) outputs value “hi”*/

#include <iostream>

class printdata {
public:
    // Overloaded print function for integer
    void print(int value) {
        std::cout << "value " << value << std::endl;
    }

    // Overloaded print function for string
    void print(const char* str) {
        std::cout << "value \"" << str << "\"" << std::endl;
    }
};

int main() {
    printdata obj;

    // Call print function for integer
    obj.print(10);

    // Call print function for string
    obj.print("hi");

    return 0;
}

/*Ouput
value 10
value "hi"
*/