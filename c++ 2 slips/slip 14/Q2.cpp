/*Write a C++ program to define a class Bus with the following specifications: Bus No, Bus
Name, No of Seats, Starting point, Destination .Write a menu driven program by using
appropriate manipulators to
a. Accept details of n buses.
b. Display all bus details.
c. Display details of bus from specified starting point to destination*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Bus {
private:
    int busNo;
    string busName;
    int seats;
    string startPoint;
    string destination;

public:
    // Constructor
    Bus(int no, const string& name, int seat, const string& start, const string& dest)
        : busNo(no), busName(name), seats(seat), startPoint(start), destination(dest) {}

    // Function to display bus details
    void displayDetails() const {
        cout << left << setw(10) << busNo << setw(20) << busName << setw(10) << seats
             << setw(15) << startPoint << setw(15) << destination << endl;
    }

    // Accessor function to get starting point
    string getStartPoint() const {
        return startPoint;
    }

    // Accessor function to get destination
    string getDestination() const {
        return destination;
    }
};


int main() {
    vector<Bus> buses;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Accept details of n buses" << endl;
        cout << "2. Display all bus details" << endl;
        cout << "3. Display details of bus from specified starting point to destination" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number of buses: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    int busNo, seats;
                    string busName, startPoint, destination;
                    cout << "Enter details for bus " << i + 1 << ":" << endl;
                    cout << "Bus No: ";
                    cin >> busNo;
                    cin.ignore(); // Clear buffer
                    cout << "Bus Name: ";
                    getline(cin, busName);
                    cout << "No of Seats: ";
                    cin >> seats;
                    cin.ignore(); // Clear buffer
                    cout << "Starting point: ";
                    getline(cin, startPoint);
                    cout << "Destination: ";
                    getline(cin, destination);

                    buses.push_back(Bus(busNo, busName, seats, startPoint, destination));
                }
                break;
            }
            case 2: {
                cout << left << setw(10) << "Bus No" << setw(20) << "Bus Name" << setw(10) << "Seats"
                     << setw(15) << "Starting Pt" << setw(15) << "Destination" << endl;
                for (const auto& bus : buses) {
                    bus.displayDetails();
                }
                break;
            }
            case 3: {
                string start, dest;
                cout << "Enter starting point: ";
                cin.ignore(); // Clear buffer
                getline(cin, start);
                cout << "Enter destination: ";
                getline(cin, dest);

                cout << left << setw(10) << "Bus No" << setw(20) << "Bus Name" << setw(10) << "Seats"
                     << setw(15) << "Starting Pt" << setw(15) << "Destination" << endl;
                for (const auto& bus : buses) {
                    if (bus.getStartPoint() == start && bus.getDestination() == dest) {
                        bus.displayDetails();
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}

/*Output:-
Menu:
1. Accept details of n buses
2. Display all bus details
3. Display details of bus from specified starting point to destination
4. Exit
Enter your choice: 1
Enter the number of buses: 2
Enter details for bus 1:
Bus No: 101
Bus Name: ABC Travels
No of Seats: 50
Starting point: City A
Destination: City B
Enter details for bus 2:
Bus No: 102
Bus Name: XYZ Travels
No of Seats: 40
Starting point: City B
Destination: City C

Menu:
1. Accept details of n buses
2. Display all bus details
3. Display details of bus from specified starting point to destination
4. Exit
Enter your choice: 2
Bus No    Bus Name            Seats     Starting Pt    Destination     
101       ABC Travels         50        City A         City B          
102       XYZ Travels         40        City B         City C          

Menu:
1. Accept details of n buses
2. Display all bus details
3. Display details of bus from specified starting point to destination
4. Exit
Enter your choice: 3
Enter starting point: City B
Enter destination: City C
Bus No    Bus Name            Seats     Starting Pt    Destination     
102       XYZ Travels         40        City B         City C          

Menu:
1. Accept details of n buses
2. Display all bus details
3. Display details of bus from specified starting point to destination
4. Exit
Enter your choice: 4
Exiting program. Goodbye!

*/