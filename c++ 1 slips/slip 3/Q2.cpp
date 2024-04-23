/*Write a C++ program with Student as abstract class and create derive classes Engineering,
Medicine and Science having data member rollno and name from base class Student. Create
objects of the derived classes and access them using array of pointer of base class Student.
*/

#include <iostream>
#include <string>

class Student {
protected:
    int rollno;
    std::string name;

public:
    Student(int roll, const std::string& n) : rollno(roll), name(n) {}

    // Virtual destructor
    virtual ~Student() {}

    // Pure virtual function making Student an abstract class
    virtual void display() const = 0;
};


class Engineering : public Student {
public:
    Engineering(int roll, const std::string& n) : Student(roll, n) {}

    void display() const override {
        std::cout << "Engineering Student - Roll No: " << rollno << ", Name: " << name << std::endl;
    }
};

class Medicine : public Student {
public:
    Medicine(int roll, const std::string& n) : Student(roll, n) {}

    void display() const override {
        std::cout << "Medicine Student - Roll No: " << rollno << ", Name: " << name << std::endl;
    }
};

class Science : public Student {
public:
    Science(int roll, const std::string& n) : Student(roll, n) {}

    void display() const override {
        std::cout << "Science Student - Roll No: " << rollno << ", Name: " << name << std::endl;
    }
};

int main() {
    const int numStudents = 3;
    Student* students[numStudents];

    // Create objects of derived classes
    students[0] = new Engineering(101, "John");
    students[1] = new Medicine(201, "Alice");
    students[2] = new Science(301, "Bob");

    // Access and display objects using array of pointers to base class
    for (int i = 0; i < numStudents; ++i) {
        students[i]->display();
    }

    // Clean up memory
    for (int i = 0; i < numStudents; ++i) {
        delete students[i];
    }

    return 0;
}

/*
Output
Engineering Student - Roll No: 101, Name: John
Medicine Student - Roll No: 201, Name: Alice
Science Student - Roll No: 301, Name: Bob
*/