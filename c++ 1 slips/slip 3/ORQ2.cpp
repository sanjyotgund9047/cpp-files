/*Create a class String which contains a character pointer (Use new and delete operator)
Write a C++ program to overload following operators
a. ! To reverse the case of each alphabet from given string.
b. [ ] To print a character present at specified index */

#include <iostream>
#include <cstring>

class String {
private:
    char *str;

public:
    // Constructor
    String(const char *s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete [] str;
    }

    // Overloading '!' operator to reverse case of each alphabet
    String operator!() const {
        String temp(*this);
        for (int i = 0; temp.str[i] != '\0'; i++) {
            if (isalpha(temp.str[i])) {
                if (islower(temp.str[i])) {
                    temp.str[i] = toupper(temp.str[i]);
                } else {
                    temp.str[i] = tolower(temp.str[i]);
                }
            }
        }
        return temp;
    }

    // Overloading '[]' operator to access character at specified index
    char operator[](int index) const {
    if (index >= 0 && index < static_cast<int>(strlen(str))) {
        return str[index];
    } else {
        std::cerr << "Index out of bounds!" << std::endl;
        return '\0';
    }
}


    // Function to display the string
    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    String myString("Hello World!");

    // Test '!' operator
    String reversedString = !myString;
    std::cout << "Reversed Case: ";
    reversedString.display();

    // Test '[]' operator
    std::cout << "Character at index 6: " << myString[6] << std::endl;

    return 0;
}
/*
Output 
Reversed Case: hELLO wORLD!
Character at index 6: w
*/