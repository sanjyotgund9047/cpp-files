/*Create a base class Flight containing protected data members as Flight_no, Flight_Name. Derive
a class Route(Source, Destination) from class Flight. Also derive a class Reservation (no_seats,
class, fare, travel_date) from Route. Write a C++ program to perform the following necessary
functions.
a. Enter details of n reservations.
b. Display reservation details of Business class.*/

#include <iostream>
#include <vector>
#include <string>

class Flight {
protected:
    int flightNo;
    std::string flightName;

public:
    // Parameterized constructor
    Flight(int no, const std::string& name) : flightNo(no), flightName(name) {}

    // Display function
    void display() const {
        std::cout << "Flight No: " << flightNo << ", Flight Name: " << flightName << std::endl;
    }
};

class Route : public Flight {
private:
    std::string source;
    std::string destination;

public:
    // Parameterized constructor
    Route(int no, const std::string& name, const std::string& src, const std::string& dest)
        : Flight(no, name), source(src), destination(dest) {}

    // Display function
    void display() const {
        Flight::display();
        std::cout << "Source: " << source << ", Destination: " << destination << std::endl;
    }
};

class Reservation : public Route {
private:
    int noSeats;
    std::string travelClass;
    float fare;
    std::string travelDate;

public:
    // Parameterized constructor
    Reservation(int no, const std::string& name, const std::string& src, const std::string& dest,
                int seats, const std::string& cls, float f, const std::string& date)
        : Route(no, name, src, dest), noSeats(seats), travelClass(cls), fare(f), travelDate(date) {}

    // Function to display reservation details
    void display() const {
        Route::display();
        std::cout << "Number of Seats: " << noSeats << ", Class: " << travelClass << ", Fare: " << fare
                  << ", Travel Date: " << travelDate << std::endl;
    }

    // Function to check if the reservation is in Business class
    bool isBusinessClass() const {
        return travelClass == "Business";
    }
};

int main() {
    int n;
    std::cout << "Enter number of reservations: ";
    std::cin >> n;

    std::vector<Reservation> reservations;

    // Input reservation details
    for (int i = 0; i < n; ++i) {
        int flightNo, seats;
        std::string flightName, source, destination, travelClass, travelDate;
        float fare;

        std::cout << "Enter details for reservation " << i+1 << ":" << std::endl;
        std::cout << "Flight No: ";
        std::cin >> flightNo;
        std::cout << "Flight Name: ";
        std::cin.ignore();
        std::getline(std::cin, flightName);
        std::cout << "Source: ";
        std::getline(std::cin, source);
        std::cout << "Destination: ";
        std::getline(std::cin, destination);
        std::cout << "Number of Seats: ";
        std::cin >> seats;
        std::cout << "Class: ";
        std::cin.ignore();
        std::getline(std::cin, travelClass);
        std::cout << "Fare: ";
        std::cin >> fare;
        std::cout << "Travel Date: ";
        std::cin.ignore();
        std::getline(std::cin, travelDate);

        reservations.push_back(Reservation(flightNo, flightName, source, destination, seats, travelClass, fare, travelDate));
    }

    // Display reservation details of Business class
    std::cout << "\nReservation details of Business class:" << std::endl;
    for (const auto& reservation : reservations) {
        if (reservation.isBusinessClass()) {
            reservation.display();
            std::cout << std::endl;
        }
    }

    return 0;
}

/*
Output
Enter number of reservations: 3
Enter details for reservation 1:
Flight No: 101
Flight Name: ABC Airlines
Source: New York
Destination: London
Number of Seats: 2
Class: Economy
Fare: 500.0
Travel Date: 2024-04-15
Enter details for reservation 2:
Flight No: 102
Flight Name: XYZ Airlines
Source: London
Destination: Paris
Number of Seats: 1
Class: Business
Fare: 1000.0
Travel Date: 2024-04-20
Enter details for reservation 3:
Flight No: 103
Flight Name: PQR Airlines
Source: Paris
Destination: Rome
Number of Seats: 3
Class: Economy
Fare: 600.0
Travel Date: 2024-04-25

Reservation details of Business class:
Flight No: 102, Flight Name: XYZ Airlines
Source: London, Destination: Paris
Number of Seats: 1, Class: Business, Fare: 1000
Travel Date: 2024-04-20

*/