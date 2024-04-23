/*Write a C++ program to create a class Date which contains three data members as dd,mm,yyyy.
Create and initialize the object by using parameterized constructor and display date in dd-monthyyyy format. (Input: 19-12-2014 Output: 19-Dec-2014) Perform validation for month.*/
#include <iostream>
#include <string>

class Date {
private:
    int dd;
    int mm;
    int yyyy;

public:
    // Parameterized constructor to initialize date
    Date(int day, int month, int year) : dd(day), mm(month), yyyy(year) {}

    // Function to display date in dd-month-yyyy format
    void displayDate() const {
        // Array to store month names
        const std::string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        // Check for valid month
        if (mm >= 1 && mm <= 12) {
            // Display date in dd-month-yyyy format
            std::cout << dd << "-" << monthNames[mm - 1] << "-" << yyyy << std::endl;
        } else {
            std::cout << "Invalid month!" << std::endl;
        }
    }
};

int main() {
    // Initialize Date object using parameterized constructor
    Date date(19, 12, 2014);

    // Display date in dd-month-yyyy format
    date.displayDate();

    return 0;
}

/*Output
19-Dec-2014
*/