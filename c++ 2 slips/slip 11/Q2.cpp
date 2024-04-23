/*Write a C++ program to create a class Person that contains data members as Person_Name, City,
Mob_No. Write a C++ program to perform following functions:
a. To accept and display Person information
b. To search the Person details of a given mobile number
c. To search the Person details of a given city.
(Use Function Overloading) */

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string Person_Name;
    string City;
    string Mob_No;

public:
    // Function to accept and display person information
    void acceptDisplay(const string& name, const string& city, const string& mobNo) {
        Person_Name = name;
        City = city;
        Mob_No = mobNo;

        cout << "Person Name: " << Person_Name << endl;
        cout << "City: " << City << endl;
        cout << "Mobile Number: " << Mob_No << endl;
    }

    // Function to search person details by mobile number
    void searchByMobile(const string& mobileNumber) {
        if (Mob_No == mobileNumber) {
            cout << "Person Name: " << Person_Name << endl;
            cout << "City: " << City << endl;
            cout << "Mobile Number: " << Mob_No << endl;
        } else {
            cout << "Person with mobile number " << mobileNumber << " not found!" << endl;
        }
    }

    // Function to search person details by city
    void searchByCity(const string& city) {
        if (City == city) {
            cout << "Person Name: " << Person_Name << endl;
            cout << "City: " << City << endl;
            cout << "Mobile Number: " << Mob_No << endl;
        } else {
            cout << "No person found in city " << city << endl;
        }
    }
};

int main() {
    Person person1, person2;

    // Accept and display person information
    cout << "Enter Person 1 information:" << endl;
    person1.acceptDisplay("Alice", "New York", "1234567890");

    cout << "\nEnter Person 2 information:" << endl;
    person2.acceptDisplay("Bob", "Los Angeles", "9876543210");

    // Search by mobile number
    cout << "\nSearch by mobile number:" << endl;
    person1.searchByMobile("1234567890");
    person2.searchByMobile("9999999999"); // Not found case

    // Search by city
    cout << "\nSearch by city:" << endl;
    person1.searchByCity("New York");
    person2.searchByCity("Chicago"); // Not found case

    return 0;
}

/*Output:-
Enter Person 1 information:
Person Name: Alice
City: New York
Mobile Number: 1234567890

Enter Person 2 information:
Person Name: Bob
City: Los Angeles
Mobile Number: 9876543210

Search by mobile number:
Person Name: Alice
City: New York
Mobile Number: 1234567890
Person with mobile number 9999999999 not found!

Search by city:
Person Name: Alice
City: New York
Mobile Number: 1234567890
No person found in city Chicago

*/