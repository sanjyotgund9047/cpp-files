/*Write a C++ program to create a text file which stores employee information as emp_id,
emp_name, emp_sal). Write a menu driven program with the options
a. Append
b. Modify
c. Display
d. Exit */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold employee information
struct Employee {
    int emp_id;
    string emp_name;
    double emp_sal;
};

// Function to append employee information to a text file
void appendEmployee(const Employee& emp) {
    ofstream outfile("employee.txt", ios::app);
    if (outfile.is_open()) {
        outfile << emp.emp_id << " " << emp.emp_name << " " << emp.emp_sal << endl;
        cout << "Employee information appended successfully." << endl;
        outfile.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
}

// Function to modify employee information in the text file
void modifyEmployee(int empId, const string& newName, double newSal) {
    ifstream infile("employee.txt");
    ofstream temp("temp.txt");
    bool found = false;
    Employee emp;
    while (infile >> emp.emp_id >> emp.emp_name >> emp.emp_sal) {
        if (emp.emp_id == empId) {
            emp.emp_name = newName;
            emp.emp_sal = newSal;
            found = true;
        }
        temp << emp.emp_id << " " << emp.emp_name << " " << emp.emp_sal << endl;
    }
    infile.close();
    temp.close();
    remove("employee.txt");
    rename("temp.txt", "employee.txt");

    if (found) {
        cout << "Employee information modified successfully." << endl;
    } else {
        cout << "Employee with ID " << empId << " not found." << endl;
    }
}

// Function to display all employee information from the text file
void displayEmployees() {
    ifstream infile("employee.txt");
    if (infile.is_open()) {
        Employee emp;
        cout << "Employee Information:" << endl;
        while (infile >> emp.emp_id >> emp.emp_name >> emp.emp_sal) {
            cout << "ID: " << emp.emp_id << ", Name: " << emp.emp_name << ", Salary: " << emp.emp_sal << endl;
        }
        infile.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
}

int main() {
    char choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "a. Append" << endl;
        cout << "b. Modify" << endl;
        cout << "c. Display" << endl;
        cout << "d. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                Employee emp;
                cout << "Enter Employee ID: ";
                cin >> emp.emp_id;
                cout << "Enter Employee Name: ";
                cin.ignore();
                getline(cin, emp.emp_name);
                cout << "Enter Employee Salary: ";
                cin >> emp.emp_sal;
                appendEmployee(emp);
                break;
            }
            case 'b': {
                int empId;
                string newName;
                double newSal;
                cout << "Enter Employee ID to modify: ";
                cin >> empId;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, newName);
                cout << "Enter new salary: ";
                cin >> newSal;
                modifyEmployee(empId, newName, newSal);
                break;
            }
            case 'c':
                displayEmployees();
                break;
            case 'd':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 'd');

    return 0;
}

/*Output:-
Menu:
a. Append
b. Modify
c. Display
d. Exit
Enter your choice: a
Enter Employee ID: 101
Enter Employee Name: Satish tonde
Enter Employee Salary: 50000
Employee information appended successfully.

Menu:
a. Append
b. Modify
c. Display
d. Exit
Enter your choice: c
Employee Information:
ID: 101, Name: John Doe, Salary: 50000

Menu:
a. Append
b. Modify
c. Display
d. Exit
Enter your choice: b
Enter Employee ID to modify: 101
Enter new name: Tejaswi Tenagle
Enter new salary: 55000
Employee information modified successfully.

Menu:
a. Append
b. Modify
c. Display
d. Exit
Enter your choice: c
Employee Information:
ID: 101, Name: Tejaswi Tengale, Salary: 55000

Menu:
a. Append
b. Modify
c. Display
d. Exit
Enter your choice: d
Exiting program...

*/