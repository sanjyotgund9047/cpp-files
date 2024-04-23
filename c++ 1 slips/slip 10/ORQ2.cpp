/*Create a class String which contains a character pointer (Use new and delete operator). Write a
C++ program to overload following operators:
a. < To compare length of two strings
b. == To check equality of two strings
c. + To concatenate two strings */

#include <iostream>
#include <cstring> // For strlen()

class String {
private:
    char* str;

public:
    // Constructor
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Copy constructor
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Less than operator (<) to compare length of two strings
    bool operator<(const String& other) const {
        return strlen(str) < strlen(other.str);
    }

    // Equality operator (==) to check equality of two strings
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Addition operator (+) to concatenate two strings
    String operator+(const String& other) const {
        char* temp = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        String result(temp);
        delete[] temp;
        return result;
    }

    // Function to display the string
    void display() const {
        std::cout << str;
    }
};

int main() {
    String s1("Hello");
    String s2("World");
    String s3("Hello");

    std::cout << "s1: ";
    s1.display();
    std::cout << std::endl;

    std::cout << "s2: ";
    s2.display();
    std::cout << std::endl;

    std::cout << "s3: ";
    s3.display();
    std::cout << std::endl;

    // Comparing lengths
    std::cout << "Length of s1 is less than length of s2: " << std::boolalpha << (s1 < s2) << std::endl;

    // Checking equality
    std::cout << "s1 and s3 are equal: " << std::boolalpha << (s1 == s3) << std::endl;

    // Concatenating strings
    String s4 = s1 + s2;
    std::cout << "Concatenated string: ";
    s4.display();
    std::cout << std::endl;

    return 0;
}

/*Output:-
s1: Hello
s2: World
s3: Hello
Length of s1 is less than length of s2: true
s1 and s3 are equal: true
Concatenated string: HelloWorld
*/