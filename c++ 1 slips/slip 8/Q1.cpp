/*Write a C++ program to subtract two integer numbers of two different classes using friend
function*/

#include <iostream>

// Forward declaration of SecondClass to let FirstClass know about it
class SecondClass;

class FirstClass {
private:
    int num;

public:
    FirstClass(int n) : num(n) {}

    // Friend function declaration
    friend int subtract(const FirstClass& first, const SecondClass& second);
};

class SecondClass {
private:
    int num;

public:
    SecondClass(int n) : num(n) {}

    // Friend function declaration
    friend int subtract(const FirstClass& first, const SecondClass& second);
};

// Friend function definition
int subtract(const FirstClass& first, const SecondClass& second) {
    return first.num - second.num;
}

int main() {
    FirstClass obj1(10);
    SecondClass obj2(5);

    // Subtracting num from obj1 and obj2 using friend function
    int result = subtract(obj1, obj2);
    
    std::cout << "Result of subtraction: " << result << std::endl;

    return 0;
}

/*output
Result of subtraction: 5
*/