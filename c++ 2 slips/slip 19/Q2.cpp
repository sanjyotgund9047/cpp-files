/*Design a two base classes Employee (Name, Designation) and Project(Project_Id, title).
Derive a class Emp_Proj(Duration) from Employee and Project. Write a menu driven
program to
a. Build a master table.
b. Display a master table
c. Display Project details in the ascending order of duration.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Base class Employee
class Employee {
protected:
    string Name;
    string Designation;

public:
    // Constructor to initialize Employee
    Employee(const string& name = "", const string& designation = "") : Name(name), Designation(designation) {}

    // Function to display employee details
    void displayEmployee() const {
        cout << "Name: " << Name << ", Designation: " << Designation << endl;
    }
};

// Base class Project
class Project {
protected:
    int Project_Id;
    string Title;

public:
    // Constructor to initialize Project
    Project(int projectId = 0, const string& title = "") : Project_Id(projectId), Title(title) {}

    // Function to display project details
    void displayProject() const {
        cout << "Project ID: " << Project_Id << ", Title: " << Title << endl;
    }
};

// Derived class Emp_Proj from Employee and Project
class Emp_Proj : public Employee, public Project {
private:
    int Duration;

public:
    // Constructor to initialize Emp_Proj
    Emp_Proj(int projectId = 0, const string& title = "", int duration = 0, const string& name = "", const string& designation = "")
        : Employee(name, designation), Project(projectId, title), Duration(duration) {}

    // Function to display Emp_Proj details
    void displayEmpProj() const {
        displayEmployee();
        displayProject();
        cout << "Duration: " << Duration << " months" << endl;
    }

    // Function to compare Emp_Proj objects based on duration for sorting
    static bool compareDuration(const Emp_Proj& empProj1, const Emp_Proj& empProj2) {
        return empProj1.Duration < empProj2.Duration;
    }
};

int main() {
    vector<Emp_Proj> masterTable;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Build a master table" << endl;
        cout << "2. Display master table" << endl;
        cout << "3. Display project details in ascending order of duration" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int projectId, duration;
                string title, name, designation;

                cout << "Enter Project ID: ";
                cin >> projectId;
                cout << "Enter Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Duration (in months): ";
                cin >> duration;
                cout << "Enter Employee Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Employee Designation: ";
                getline(cin, designation);

                masterTable.push_back(Emp_Proj(projectId, title, duration, name, designation));
                break;
            }
            case 2: {
                cout << "\nMaster Table:" << endl;
                for (const auto& empProj : masterTable) {
                    empProj.displayEmpProj();
                    cout << endl;
                }
                break;
            }
            case 3: {
                if (masterTable.empty()) {
                    cout << "Master Table is empty. Please build the master table first." << endl;
                } else {
                    cout << "\nProject Details in ascending order of duration:" << endl;
                    vector<Emp_Proj> sortedTable = masterTable;
                    sort(sortedTable.begin(), sortedTable.end(), Emp_Proj::compareDuration);
                    for (const auto& empProj : sortedTable) {
                        empProj.displayEmpProj();
                        cout << endl;
                    }
                }
                break;
            }
            case 4: {
                cout << "Exiting program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a valid choice." << endl;
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

/*Output:-
Menu:
1. Build a master table
2. Display master table
3. Display project details in ascending order of duration
4. Exit
Enter your choice: 1

Enter Project ID: 101
Enter Title: Project A
Enter Duration (in months): 6
Enter Employee Name: Satish Tonde
Enter Employee Designation: Software Engineer

Menu:
1. Build a master table
2. Display master table
3. Display project details in ascending order of duration
4. Exit
Enter your choice: 1

Enter Project ID: 102
Enter Title: Project B
Enter Duration (in months): 8
Enter Employee Name: Tejaswi Tengale
Enter Employee Designation: Project Manager

Menu:
1. Build a master table
2. Display master table
3. Display project details in ascending order of duration
4. Exit
Enter your choice: 2

Master Table:
Name: Satish Tonde, Designation: Software Engineer
Project ID: 101, Title: Project A
Duration: 6 months

Name: Tejaswi Tengale, Designation: Project Manager
Project ID: 102, Title: Project B
Duration: 8 months

Menu:
1. Build a master table
2. Display master table
3. Display project details in ascending order of duration
4. Exit
Enter your choice: 3

Project Details in ascending order of duration:
Name: Satish Tonde, Designation: Software Engineer
Project ID: 101, Title: Project A
Duration: 6 months

Name: Tejaswi Tengale, Designation: Project Manager
Project ID: 102, Title: Project B
Duration: 8 months

Menu:
1. Build a master table
2. Display master table
3. Display project details in ascending order of duration
4. Exit
Enter your choice: 4

Exiting program...

*/