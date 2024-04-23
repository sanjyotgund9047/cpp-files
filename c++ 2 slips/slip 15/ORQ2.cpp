/*Write C++ program to create a class Employee containing data members Emp_no, Emp_Name,
Designation and Salary. Create and initialize the objects using default, parameterized and Copy
Constructor. Also write member function to calculate Income tax of the employee which is 20%
of salary.*/

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int Emp_no;
    string Emp_Name;
    string Designation;
    double Salary;

public:
    // Default constructor
    Employee() : Emp_no(0), Emp_Name(""), Designation(""), Salary(0.0) {}

    // Parameterized constructor
    Employee(int empNo, const string& empName, const string& designation, double salary)
        : Emp_no(empNo), Emp_Name(empName), Designation(designation), Salary(salary) {}

    // Copy constructor
    Employee(const Employee& other)
        : Emp_no(other.Emp_no), Emp_Name(other.Emp_Name), Designation(other.Designation), Salary(other.Salary) {}

    // Member function to calculate income tax (20% of salary)
    double calculateIncomeTax() {
        return 0.2 * Salary;
    }

    // Display employee details
    void displayDetails() {
        cout << "Employee Details:" << endl;
        cout << "Employee Number: " << Emp_no << endl;
        cout << "Employee Name: " << Emp_Name << endl;
        cout << "Designation: " << Designation << endl;
        cout << "Salary: " << Salary << endl;
        cout << "Income Tax: " << calculateIncomeTax() << endl;
    }
};

int main() {
    // Default constructor
    Employee emp1;
    cout << "Default Constructor:" << endl;
    emp1.displayDetails();
    cout << endl;

    // Parameterized constructor
    Employee emp2(101, "Sameer Raj", "Manager", 50000.0);
    cout << "Parameterized Constructor:" << endl;
    emp2.displayDetails();
    cout << endl;

    // Copy constructor
    Employee emp3 = emp2;
    cout << "Copy Constructor:" << endl;
    emp3.displayDetails();
    cout << endl;

    return 0;
}

/*Output:-
Default Constructor:
Employee Details:
Employee Number: 0
Employee Name:
Designation:
Salary: 0
Income Tax: 0

Parameterized Constructor:
Employee Details:
Employee Number: 101
Employee Name: Sameer Raj
Designation: Manager
Salary: 50000
Income Tax: 10000

Copy Constructor:
Employee Details:
Employee Number: 101
Employee Name: Sameer Raj
Designation: Manager
Salary: 50000
Income Tax: 10000
*/