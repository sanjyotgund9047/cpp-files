/*Create a Base class Train containing protected data members as Train_no, Train_Name. Derive a
class Route(Route_id, Source, Destination) from Train class. Also derive a class Reservation
(Number_of_Seats, Train_Class, Fare, Travel_Date) from Route. Write a C++ program
to perform following necessary functions:
a. Enter details of n reservations
b. Display details of all reservations
c. Display reservation details of a specified Train class*/

#include <iostream>
#include <vector>
#include <string>

class Train {
protected:
    int Train_no;
    std::string Train_Name;
};

class Route : public Train {
public:
    int Route_id;
    std::string Source;
    std::string Destination;
};

class Reservation : public Route {
public:
    int Number_of_Seats;
    std::string Train_Class;
    double Fare;
    std::string Travel_Date;
};

int main() {
    int n;
    std::cout << "Enter the number of reservations: ";
    std::cin >> n;

    std::vector<Reservation> reservations(n);

    // Enter details of n reservations
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter details for reservation " << i + 1 << ":\n";
        std::cout << "Number of Seats: ";
        std::cin >> reservations[i].Number_of_Seats;
        std::cout << "Train Class: ";
        std::cin >> reservations[i].Train_Class;
        std::cout << "Fare: ";
        std::cin >> reservations[i].Fare;
        std::cout << "Travel Date: ";
        std::cin >> reservations[i].Travel_Date;
    }

    // Display details of all reservations
    std::cout << "\nAll Reservations:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Reservation " << i + 1 << ":\n";
        std::cout << "Number of Seats: " << reservations[i].Number_of_Seats << "\n";
        std::cout << "Train Class: " << reservations[i].Train_Class << "\n";
        std::cout << "Fare: " << reservations[i].Fare << "\n";
        std::cout << "Travel Date: " << reservations[i].Travel_Date << "\n";
    }

    // Display reservation details of a specified Train class
    std::string specifiedClass;
    std::cout << "\nEnter the Train Class to display reservation details: ";
    std::cin >> specifiedClass;

    std::cout << "\nReservations for Train Class " << specifiedClass << ":\n";
    for (int i = 0; i < n; ++i) {
        if (reservations[i].Train_Class == specifiedClass) {
            std::cout << "Reservation " << i + 1 << ":\n";
            std::cout << "Number of Seats: " << reservations[i].Number_of_Seats << "\n";
            std::cout << "Fare: " << reservations[i].Fare << "\n";
            std::cout << "Travel Date: " << reservations[i].Travel_Date << "\n";
        }
    }

    return 0;
}


/*Output:-
Enter the number of reservations: 2
Enter details for reservation 1:
Number of Seats: 3
Train Class: First
Fare: 50.5
Travel Date: 2024-05-01
Enter details for reservation 2:
Number of Seats: 2
Train Class: Second
Fare: 30.75
Travel Date: 2024-05-03

All Reservations:
Reservation 1:
Number of Seats: 3
Train Class: First
Fare: 50.5
Travel Date: 2024-05-01
Reservation 2:
Number of Seats: 2
Train Class: Second
Fare: 30.75
Travel Date: 2024-05-03

Enter the Train Class to display reservation details: First

Reservations for Train Class First:
Reservation 1:
Number of Seats: 3
Fare: 50.5
Travel Date: 2024-05-01

*/