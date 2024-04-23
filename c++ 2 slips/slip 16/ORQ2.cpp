/*Create a class Time containing members as:
- hours
- minutes
- seconds
Write a C++ program for overloading operators >> and << to accept and display a Time
also write a member function to display time in total seconds. */

#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time() : hours(0), minutes(0), seconds(0) {}

    // Overloaded insertion operator (>>) to accept a Time object
    friend istream& operator>>(istream& in, Time& t) {
        cout << "Enter hours: ";
        in >> t.hours;
        cout << "Enter minutes: ";
        in >> t.minutes;
        cout << "Enter seconds: ";
        in >> t.seconds;
        return in;
    }

    // Overloaded extraction operator (<<) to display a Time object
    friend ostream& operator<<(ostream& out, const Time& t) {
        out << "Time: " << t.hours << " hours, " << t.minutes << " minutes, " << t.seconds << " seconds";
        return out;
    }

    // Member function to display time in total seconds
    int totalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
};

int main() {
    Time t1;

    // Input time from user
    cout << "Enter time:" << endl;
    cin >> t1;

    // Display time
    cout << "Time entered: " << t1 << endl;

    // Display time in total seconds
    cout << "Total seconds: " << t1.totalSeconds() << endl;

    return 0;
}

/*Output:-
Enter time:
Enter hours: 1
Enter minutes: 30
Enter seconds: 45
Time entered: Time: 1 hours, 30 minutes, 45 seconds
Total seconds: 5445
*/