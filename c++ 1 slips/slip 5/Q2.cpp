/*Create a base class Student (Roll_No, Name) which derives two classes Theory and Practical.
Theory class contains marks of five Subjects and Practical class contains marks of two practical
subjects. Class Result (Total_Marks, Class) inherits both Theory and Practical classes. (Use
concept of Virtual Base Class) Write a menu driven program to perform the following functions:
a. Build a master table.
b. Display master table. */

#include <iostream>
#include <string>

class Student {
protected:
    int rollNo;
    std::string name;

public:
    // Parameterized constructor
    Student(int roll, const std::string& n) : rollNo(roll), name(n) {}

    // Virtual function to display student details
    virtual void display() const {
        std::cout << "Roll No: " << rollNo << ", Name: " << name << std::endl;
    }
};

class Theory : virtual public Student {
protected:
    int subject1, subject2, subject3, subject4, subject5;

public:
    // Parameterized constructor
    Theory(int roll, const std::string& n, int s1, int s2, int s3, int s4, int s5)
        : Student(roll, n), subject1(s1), subject2(s2), subject3(s3), subject4(s4), subject5(s5) {}

    // Virtual function to display theory marks
    virtual void display() const {
        Student::display();
        std::cout << "Theory Marks: " << subject1 << ", " << subject2 << ", " << subject3 << ", " << subject4 << ", " << subject5 << std::endl;
    }
};

class Practical : virtual public Student {
protected:
    int practical1, practical2;

public:
    // Parameterized constructor
    Practical(int roll, const std::string& n, int p1, int p2)
        : Student(roll, n), practical1(p1), practical2(p2) {}

    // Virtual function to display practical marks
    virtual void display() const {
        Student::display();
        std::cout << "Practical Marks: " << practical1 << ", " << practical2 << std::endl;
    }
};

class Result : public Theory, public Practical {
private:
    int totalMarks;
    std::string studentClass;

public:
    // Parameterized constructor
    Result(int roll, const std::string& n, int s1, int s2, int s3, int s4, int s5, int p1, int p2, int total, const std::string& cls)
        : Student(roll, n), Theory(roll, n, s1, s2, s3, s4, s5), Practical(roll, n, p1, p2), totalMarks(total), studentClass(cls) {}

    // Function to display result
    void display() const {
        std::cout << "Student Result:" << std::endl;
        Student::display();
        std::cout << "Total Marks: " << totalMarks << ", Class: " << studentClass << std::endl;
    }
};

int main() {
    Result student1(101, "John", 80, 85, 75, 90, 88, 90, 85, 508, "First");
    Result student2(102, "Alice", 75, 80, 70, 85, 82, 88, 80, 520, "First");

    // Display master table
    std::cout << "Master Table:" << std::endl;
    student1.display();
    student2.display();

    return 0;
}

/*Output
Master Table:
Student Result:
Roll No: 101, Name: John
Theory Marks: 80, 85, 75, 90, 88
Practical Marks: 90, 85
Total Marks: 508, Class: First
Student Result:
Roll No: 102, Name: Alice
Theory Marks: 75, 80, 70, 85, 82
Practical Marks: 88, 80
Total Marks: 520, Class: First

*/