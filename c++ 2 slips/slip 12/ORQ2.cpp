/*Implement the following class hierarchy:
Employee: code, ename, desg
Manager (derived from Employee): year_of_experience, salary
Define appropriate functions to accept and display details.
Create n objects of the manager class and display the records.
Write main function that uses the above class and its member functions.*/

#include <iostream>
#include <string>

using namespace std;

// Base class Employee
class Employee {
protected:
    int code;
    string ename;
    string desg;

public:
    // Function to accept employee details
    void acceptDetails() {
        cout << "Enter Employee Code: ";
        cin >> code;
        cout << "Enter Employee Name: ";
        cin >> ename;
        cout << "Enter Employee Designation: ";
        cin >> desg;
    }

    // Function to display employee details
    void displayDetails() {
        cout << "Employee Code: " << code << endl;
        cout << "Employee Name: " << ename << endl;
        cout << "Employee Designation: " << desg << endl;
    }
};

// Derived class Manager from Employee
class Manager : public Employee {
private:
    int year_of_experience;
    double salary;

public:
    // Function to accept manager details
    void acceptDetails() {
        Employee::acceptDetails(); // Accepting base class details
        cout << "Enter Years of Experience: ";
        cin >> year_of_experience;
        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display manager details
    void displayDetails() {
        Employee::displayDetails(); // Displaying base class details
        cout << "Years of Experience: " << year_of_experience << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of managers: ";
    cin >> n;

    Manager* managers = new Manager[n];

    // Accept details for each manager
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Manager " << i + 1 << ":" << endl;
        managers[i].acceptDetails();
    }

    // Display details for each manager
    cout << "\nManager Details:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "\nDetails for Manager " << i + 1 << ":" << endl;
        managers[i].displayDetails();
    }

    delete[] managers; // Freeing memory allocated for managers

    return 0;
}


/*Output:-
Enter the number of managers: 2

Enter details for Manager 1:
Enter Employee Code: 101
Enter Employee Name: John
Enter Employee Designation: Manager
Enter Years of Experience: 5
Enter Salary: 60000

Enter details for Manager 2:
Enter Employee Code: 102
Enter Employee Name: Alice
Enter Employee Designation: Senior Manager
Enter Years of Experience: 8
Enter Salary: 80000

Manager Details:

Details for Manager 1:
Employee Code: 101
Employee Name: John
Employee Designation: Manager
Years of Experience: 5
Salary: 60000

Details for Manager 2:
Employee Code: 102
Employee Name: Alice
Employee Designation: Senior Manager
Years of Experience: 8
Salary: 80000

*/