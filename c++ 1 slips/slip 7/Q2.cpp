/*Create a class College containing data members as College_Id, College_Name,
Establishment_year, University_Name. Write a C++ program with following functions
a. Accept n College details
b. Display College details of specified University
c. Display College details according to Establishment year (Use Array of Objects and
Function Overloading).*/
#include <iostream>
#include <string>

class College {
private:
    int collegeId;
    std::string collegeName;
    int establishmentYear;
    std::string universityName;

public:
    // Default constructor
    College() {}

    // Parameterized constructor
    College(int id, const std::string& name, int year, const std::string& uni)
        : collegeId(id), collegeName(name), establishmentYear(year), universityName(uni) {}

    // Function to accept college details
    void acceptDetails() {
        std::cout << "Enter College ID: ";
        std::cin >> collegeId;
        std::cin.ignore(); // Ignore newline character
        std::cout << "Enter College Name: ";
        std::getline(std::cin, collegeName);
        std::cout << "Enter Establishment Year: ";
        std::cin >> establishmentYear;
        std::cin.ignore(); // Ignore newline character
        std::cout << "Enter University Name: ";
        std::getline(std::cin, universityName);
    }

    // Function to display college details
    void display() const {
        std::cout << "College ID: " << collegeId << ", Name: " << collegeName
                  << ", Establishment Year: " << establishmentYear
                  << ", University Name: " << universityName << std::endl;
    }

    // Function to display college details for a specified university
    void display(const std::string& uni) const {
        if (universityName == uni) {
            display();
        }
    }

    // Function to display college details according to establishment year
    void display(int year) const {
        if (establishmentYear == year) {
            display();
        }
    }
};

int main() {
    const int MAX_COLLEGES = 3;
    College colleges[MAX_COLLEGES];

    // Accept college details
    std::cout << "Enter details for " << MAX_COLLEGES << " colleges:" << std::endl;
    for (int i = 0; i < MAX_COLLEGES; ++i) {
        std::cout << "Details for college " << i + 1 << ":" << std::endl;
        colleges[i].acceptDetails();
    }

    // Display college details of specified university
    std::string specifiedUniversity;
    std::cout << "\nEnter the university name to display its colleges: ";
    std::getline(std::cin, specifiedUniversity);
    std::cout << "Colleges under " << specifiedUniversity << ":" << std::endl;
    for (int i = 0; i < MAX_COLLEGES; ++i) {
        colleges[i].display(specifiedUniversity);
    }

    // Display college details according to establishment year
    int specifiedYear;
    std::cout << "\nEnter the establishment year to display colleges established in that year: ";
    std::cin >> specifiedYear;
    std::cout << "Colleges established in " << specifiedYear << ":" << std::endl;
    for (int i = 0; i < MAX_COLLEGES; ++i) {
        colleges[i].display(specifiedYear);
    }

    return 0;
}

/*Output
Enter details for 3 colleges:
Details for college 1:
Enter College ID: 101
Enter College Name: ABC College
Enter Establishment Year: 2000
Enter University Name: XYZ University
Details for college 2:
Enter College ID: 102
Enter College Name: DEF College
Enter Establishment Year: 1995
Enter University Name: XYZ University
Details for college 3:
Enter College ID: 103
Enter College Name: GHI College
Enter Establishment Year: 2010
Enter University Name: PQR University

Enter the university name to display its colleges: XYZ University
Colleges under XYZ University:
College ID: 101, Name: ABC College, Establishment Year: 2000, University Name: XYZ University
College ID: 102, Name: DEF College, Establishment Year: 1995, University Name: XYZ University

Enter the establishment year to display colleges established in that year: 2010
Colleges established in 2010:
College ID: 103, Name: GHI College, Establishment Year: 2010, University Name: PQR University

*/