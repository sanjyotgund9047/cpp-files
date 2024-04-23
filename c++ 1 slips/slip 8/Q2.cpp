/*Create a class String which contains a character pointer (Use new and delete operator).
Write a C++ program to overload following operators:
a. ! To reverse the case of each alphabet from given string
b. == To check equality of two strings */

#include <iostream>
#include <cstring>

class String {
private:
    char *str;

public:
    // Constructor
    String(const char *s = "") {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete [] str;
    }

    // Copy constructor
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Assignment operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete [] str;
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    // Overloading ! operator to reverse the case of each alphabet
    String operator!() const {
        String temp(*this);
        for (int i = 0; temp.str[i] != '\0'; ++i) {
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

    // Overloading == operator to check equality of two strings
    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Function to display string
    void display() const {
        std::cout << str;
    }
};

int main() {
    String s1("Hello");
    String s2("WORLD");
    
    std::cout << "Original Strings:" << std::endl;
    std::cout << "s1: "; s1.display(); std::cout << std::endl;
    std::cout << "s2: "; s2.display(); std::cout << std::endl;
    
    String s3 = !s1;
    String s4 = !s2;
    
    std::cout << "\nStrings after reversing case:" << std::endl;
    std::cout << "s3: "; s3.display(); std::cout << std::endl;
    std::cout << "s4: "; s4.display(); std::cout << std::endl;
    
    if (s1 == s2) {
        std::cout << "\ns1 and s2 are equal" << std::endl;
    } else {
        std::cout << "\ns1 and s2 are not equal" << std::endl;
    }
    
    if (s1 == s3) {
        std::cout << "s1 and s3 are equal" << std::endl;
    } else {
        std::cout << "s1 and s3 are not equal" << std::endl;
    }

    return 0;
}

/*Output
Original Strings:
s1: Hello
s2: WORLD

Strings after reversing case:
s3: hELLO
s4: world

s1 and s2 are not equal
s1 and s3 are not equal

*/