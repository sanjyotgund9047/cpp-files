/*Create two base classes Learn_Info(Roll_No, Stud_Name, Class, Percentage) and
Earn_Info(No_of_hours_worked, Charges_per_hour). Derive a class Earn_Learn_info from
above two classes. Write necessary member functions to accept and display Student
information. Calculate total money earned by the student. (Use constructor in derived class)
*/

#include <iostream>
#include <string>

using namespace std;

// Base class for learning information
class Learn_Info {
protected:
    int Roll_No;
    string Stud_Name;
    string Class;
    float Percentage;

public:
    // Parameterized constructor for Learn_Info
    Learn_Info(int rollNo, const string& studName, const string& studentClass, float percentage)
        : Roll_No(rollNo), Stud_Name(studName), Class(studentClass), Percentage(percentage) {}

    // Display student information
    void displayInfo() {
        cout << "Roll No: " << Roll_No << endl;
        cout << "Student Name: " << Stud_Name << endl;
        cout << "Class: " << Class << endl;
        cout << "Percentage: " << Percentage << "%" << endl;
    }
};

// Base class for earning information
class Earn_Info {
protected:
    int No_of_hours_worked;
    float Charges_per_hour;

public:
    // Parameterized constructor for Earn_Info
    Earn_Info(int hoursWorked, float chargesPerHour)
        : No_of_hours_worked(hoursWorked), Charges_per_hour(chargesPerHour) {}

    // Calculate total money earned
    float calculateTotalMoneyEarned() {
        return No_of_hours_worked * Charges_per_hour;
    }
};

// Derived class from Learn_Info and Earn_Info
class Earn_Learn_Info : public Learn_Info, public Earn_Info {
public:
    // Constructor for Earn_Learn_Info
    Earn_Learn_Info(int rollNo, const string& studName, const string& studentClass, float percentage,
                     int hoursWorked, float chargesPerHour)
        : Learn_Info(rollNo, studName, studentClass, percentage),
          Earn_Info(hoursWorked, chargesPerHour) {}

    // Display student information including money earned
    void displayInfoWithEarnings() {
        displayInfo();
        cout << "Total Money Earned: $" << calculateTotalMoneyEarned() << endl;
    }
};

int main() {
    // Create an object of Earn_Learn_Info
    Earn_Learn_Info student(101, "Satish Tonde", "Class 10", 85.5, 20, 15.0);

    // Display student information including money earned
    cout << "Student Information with Earnings:" << endl;
    student.displayInfoWithEarnings();

    return 0;
}

/*Output:-
Student Information with Earnings:
Roll No: 101
Student Name: Satish Tonde
Class: Class 10
Percentage: 85.5%
Total Money Earned: $300
*/