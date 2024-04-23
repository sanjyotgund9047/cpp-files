/*Write a C++ program to create a class Mobile which contains data members as Mobile_Id,
Mobile_Name, Mobile_Price. Create and Initialize all values of Mobile object by using
parameterized constructor. Display the values of Mobile object. */

#include <iostream>
#include <string>

class Mobile {
private:
    int mobileId;
    std::string mobileName;
    float mobilePrice;

public:
    // Parameterized constructor
    Mobile(int id, const std::string& name, float price)
        : mobileId(id), mobileName(name), mobilePrice(price) {}

    // Function to display mobile details
    void display() const {
        std::cout << "Mobile ID: " << mobileId << std::endl;
        std::cout << "Mobile Name: " << mobileName << std::endl;
        std::cout << "Mobile Price: " << mobilePrice << std::endl;
    }
};

int main() {
    // Create and initialize Mobile object using parameterized constructor
    Mobile mobile1(101, "iPhone 13", 999.99);

    // Display the values of Mobile object
    std::cout << "Details of Mobile 1:" << std::endl;
    mobile1.display();

    return 0;
}

/*Output
Details of Mobile 1:
Mobile ID: 101
Mobile Name: iPhone 13
Mobile Price: 999.99
*/