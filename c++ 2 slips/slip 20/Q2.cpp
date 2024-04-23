/*Write a C++ program to create a class Department which contains data members as
Dept_Id, Dept_Name, H.O.D., Number_Of_staff. Write necessary member functions to
a. Accept details from user for ‘n’ departments and write it in a file “Dept.txt”.
b. Display details of department from a file.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Class Department
class Department {
private:
    int Dept_Id;
    string Dept_Name;
    string HOD;
    int Number_Of_Staff;

public:
    // Function to accept details of department from user
    void acceptDepartmentDetails() {
        cout << "Enter Department ID: ";
        cin >> Dept_Id;
        cout << "Enter Department Name: ";
        cin.ignore();
        getline(cin, Dept_Name);
        cout << "Enter H.O.D.: ";
        getline(cin, HOD);
        cout << "Enter Number of Staff: ";
        cin >> Number_Of_Staff;
    }

    // Function to display details of department
    void displayDepartmentDetails() const {
        cout << "Department ID: " << Dept_Id << endl;
        cout << "Department Name: " << Dept_Name << endl;
        cout << "H.O.D.: " << HOD << endl;
        cout << "Number of Staff: " << Number_Of_Staff << endl;
    }

    // Function to write department details to a file
    void writeToFile(ofstream& outfile) const {
        outfile << Dept_Id << "," << Dept_Name << "," << HOD << "," << Number_Of_Staff << endl;
    }

    // Function to read department details from a file
    void readFromFile(ifstream& infile) {
        char comma;
        infile >> Dept_Id >> comma;
        getline(infile, Dept_Name, ',');
        getline(infile, HOD, ',');
        infile >> Number_Of_Staff;
    }
};

int main() {
    int n;
    cout << "Enter the number of departments: ";
    cin >> n;

    // Create an array of Department objects to hold details of n departments
    Department departments[n];

    // Accept details of departments from user and write them to file
    ofstream outfile("Dept.txt");
    if (outfile.is_open()) {
        for (int i = 0; i < n; ++i) {
            cout << "\nEnter details for Department " << i + 1 << ":" << endl;
            departments[i].acceptDepartmentDetails();
            departments[i].writeToFile(outfile);
        }
        outfile.close();
        cout << "\nDepartment details have been written to file \"Dept.txt\"." << endl;
    } else {
        cout << "Unable to open the file for writing." << endl;
        return 1;
    }

    // Display department details from file
    ifstream infile("Dept.txt");
    if (infile.is_open()) {
        cout << "\nDepartment details from file \"Dept.txt\":" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "\nDetails for Department " << i + 1 << ":" << endl;
            departments[i].readFromFile(infile);
            departments[i].displayDepartmentDetails();
        }
        infile.close();
    } else {
        cout << "Unable to open the file for reading." << endl;
        return 1;
    }

    return 0;
}

/*Output:-
Enter the number of departments: 2

Enter details for Department 1:
Enter Department ID: 101
Enter Department Name: Engineering
Enter H.O.D.: Suvarna Patil
Enter Number of Staff: 25

Enter details for Department 2:
Enter Department ID: 102
Enter Department Name: Finance
Enter H.O.D.: Sanjay Manavatkar
Enter Number of Staff: 20

Department details have been written to file "Dept.txt".

Department details from file "Dept.txt":

Details for Department 1:
Department ID: 101
Department Name: Engineering
H.O.D.: Suvarna Patil
Number of Staff: 25

Details for Department 2:
Department ID: 102
Department Name: Finance
H.O.D.: Sanjay Manavatkar
Number of Staff: 20
*/