/*Write a C++ program to create a class employee containing salary as a data member. Write
necessary member functions to overload the operator unary pre and post decrement "--"
for decrementing salary*/

#include <iostream>

class Employee {
private:
    double salary;

public:
    // Constructor
    Employee(double initialSalary) : salary(initialSalary) {}

    // Unary pre-decrement operator overload
    Employee& operator--() {
        --salary;
        return *this;
    }

    // Unary post-decrement operator overload
    Employee operator--(int) {
        Employee temp(*this);
        --salary;
        return temp;
    }

    // Function to get current salary
    double getSalary() const {
        return salary;
    }
};

int main() {
    // Create an employee with an initial salary of 5000
    Employee emp(5000);

    std::cout << "Initial salary: " << emp.getSalary() << std::endl;

    // Pre-decrement the salary
    --emp;
    std::cout << "Salary after pre-decrement: " << emp.getSalary() << std::endl;

    // Post-decrement the salary
    Employee emp2 = emp--;
    std::cout << "Salary after post-decrement: " << emp2.getSalary() << std::endl;
    std::cout << "Salary of original employee after post-decrement: " << emp.getSalary() << std::endl;

    return 0;
}

/*Output:-
Initial salary: 5000
Salary after pre-decrement: 4999
Salary after post-decrement: 4999
Salary of original employee after post-decrement: 4998
*/