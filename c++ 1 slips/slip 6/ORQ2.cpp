/*Design two base classes Employee (Name, Designation) and Project (Project_Id, title). Derive
a class Emp_Proj(Duration) from Employee and Project. Write a menu driven program to
a. Build a master table. Display a master table
b. Display Project details in the ascending order of duration. */

#include <iostream>
#include <vector>
#include <algorithm>

class Employee {
protected:
    std::string name;
    std::string designation;

public:
    // Parameterized constructor for Employee
    Employee(const std::string& n, const std::string& desig)
        : name(n), designation(desig) {}

    // Function to display employee details
    void display() const {
        std::cout << "Name: " << name << ", Designation: " << designation;
    }
};

class Project {
protected:
    int projectId;
    std::string title;

public:
    // Parameterized constructor for Project
    Project(int id, const std::string& t) : projectId(id), title(t) {}

    // Function to display project details
    void display() const {
        std::cout << "Project ID: " << projectId << ", Title: " << title;
    }
};

class Emp_Proj : public Employee, public Project {
private:
    int duration;

public:
    // Parameterized constructor for Emp_Proj
    Emp_Proj(const std::string& n, const std::string& desig, int id, const std::string& t, int dur)
        : Employee(n, desig), Project(id, t), duration(dur) {}

    // Function to display employee and project details
    void display() const {
        Employee::display();
        std::cout << ", ";
        Project::display();
        std::cout << ", Duration: " << duration << " months" << std::endl;
    }

    // Function to compare durations for sorting
    static bool compareDuration(const Emp_Proj& ep1, const Emp_Proj& ep2) {
        return ep1.duration < ep2.duration;
    }
};

int main() {
    std::vector<Emp_Proj> masterTable;

    // Build master table
    masterTable.push_back(Emp_Proj("John", "Developer", 101, "ProjectA", 6));
    masterTable.push_back(Emp_Proj("Alice", "Manager", 102, "ProjectB", 8));
    masterTable.push_back(Emp_Proj("Bob", "Designer", 103, "ProjectC", 7));

    // Display master table
    std::cout << "Master Table:" << std::endl;
    for (const auto& ep : masterTable) {
        ep.display();
    }

    std::cout << std::endl;

    // Sort projects by duration
    std::sort(masterTable.begin(), masterTable.end(), Emp_Proj::compareDuration);

    // Display projects in ascending order of duration
    std::cout << "Projects in Ascending Order of Duration:" << std::endl;
    for (const auto& ep : masterTable) {
        ep.display();
    }

    return 0;
}

/*Output
Master Table:
Name: John, Designation: Developer, Project ID: 101, Title: ProjectA, Duration: 6 months
Name: Alice, Designation: Manager, Project ID: 102, Title: ProjectB, Duration: 8 months
Name: Bob, Designation: Designer, Project ID: 103, Title: ProjectC, Duration: 7 months

Projects in Ascending Order of Duration:
Name: John, Designation: Developer, Project ID: 101, Title: ProjectA, Duration: 6 months
Name: Bob, Designation: Designer, Project ID: 103, Title: ProjectC, Duration: 7 months
Name: Alice, Designation: Manager, Project ID: 102, Title: ProjectB, Duration: 8 months

*/