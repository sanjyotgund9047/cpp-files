/*Write a C++ program to read student information such as rollno, name and percentage of n
students. Write the student information using file handling.*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold student information
struct Student {
    int rollNo;
    string name;
    float percentage;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // Create an array of Student objects to hold information of n students
    Student students[n];

    // Input student information
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Percentage: ";
        cin >> students[i].percentage;
    }

    // Open a file for writing
    ofstream outfile("student_info.txt");

    // Write student information to the file
    if (outfile.is_open()) {
        for (int i = 0; i < n; ++i) {
            outfile << "Student " << i + 1 << ":\n";
            outfile << "Roll No: " << students[i].rollNo << "\n";
            outfile << "Name: " << students[i].name << "\n";
            outfile << "Percentage: " << students[i].percentage << "\n\n";
        }
        cout << "Student information has been written to the file." << endl;
        outfile.close();
    } else {
        cout << "Unable to open the file for writing." << endl;
    }

    return 0;
}

/*Output:-
Enter the number of students: 3
Enter details for student 1:
Roll No: 101
Name: Satish
Percentage: 85.5
Enter details for student 2:
Roll No: 102
Name: Gaurav
Percentage: 90.2
Enter details for student 3:
Roll No: 103
Name: Tejaswi
Percentage: 78.3
Student information has been written to the file.
*/