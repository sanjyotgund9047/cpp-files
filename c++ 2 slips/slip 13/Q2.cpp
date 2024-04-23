/*Write a C++ programto create a class Distance which contains data members as kilometer, meter.
Write a program to perform the following functions
a.To accept distance
b.To display distance
c.To overload > operator to compare two distance*/

#include <iostream>

using namespace std;

class Distance {
private:
    int kilometer;
    int meter;

public:
    // Function to accept distance
    void acceptDistance() {
        cout << "Enter distance in kilometers: ";
        cin >> kilometer;
        cout << "Enter distance in meters: ";
        cin >> meter;
    }

    // Function to display distance
    void displayDistance() {
        cout << "Distance: " << kilometer << " kilometers and " << meter << " meters" << endl;
    }

    // Overloading > operator to compare two distances
    bool operator>(const Distance& d) {
        if (kilometer > d.kilometer)
            return true;
        else if (kilometer == d.kilometer && meter > d.meter)
            return true;
        else
            return false;
    }
};

int main() {
    Distance d1, d2;

    // Accept distance for d1 and d2
    cout << "Enter distance for first object:\n";
    d1.acceptDistance();

    cout << "\nEnter distance for second object:\n";
    d2.acceptDistance();

    // Display distance for d1 and d2
    cout << "\nDistance for first object:\n";
    d1.displayDistance();

    cout << "\nDistance for second object:\n";
    d2.displayDistance();

    // Compare distances using > operator
    if (d1 > d2)
        cout << "\nFirst distance is greater than second distance." << endl;
    else
        cout << "\nSecond distance is greater than or equal to first distance." << endl;

    return 0;
}

/*Output:-
Enter distance for first object:
Enter distance in kilometers: 5
Enter distance in meters: 500

Enter distance for second object:
Enter distance in kilometers: 6
Enter distance in meters: 200

Distance for first object:
Distance: 5 kilometers and 500 meters

Distance for second object:
Distance: 6 kilometers and 200 meters

Second distance is greater than or equal to first distance.
*/