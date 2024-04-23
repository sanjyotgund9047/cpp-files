/*Create a class Time which contains data members as: Hours, Minutes and Seconds. Write a
C++ program to perform following necessary member functions:
a. To read time
b. To display time in format like: hh:mm:ss
c. To add two different times (Use Objects as argument)*/

#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Function to read time
    void readTime() {
        std::cout << "Enter hours: ";
        std::cin >> hours;
        std::cout << "Enter minutes: ";
        std::cin >> minutes;
        std::cout << "Enter seconds: ";
        std::cin >> seconds;
    }

    // Function to display time in format: hh:mm:ss
    void displayTime() {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    // Function to add two different times (Use Objects as argument)
    Time addTime(const Time& t2) {
        Time sum;
        sum.seconds = seconds + t2.seconds;
        sum.minutes = minutes + t2.minutes + sum.seconds / 60;
        sum.hours = hours + t2.hours + sum.minutes / 60;

        sum.seconds %= 60;
        sum.minutes %= 60;
        sum.hours %= 24;

        return sum;
    }
};

int main() {
    Time t1, t2, sum;

    std::cout << "Enter the first time:" << std::endl;
    t1.readTime();

    std::cout << "Enter the second time:" << std::endl;
    t2.readTime();

    std::cout << "First time: ";
    t1.displayTime();
    std::cout << "Second time: ";
    t2.displayTime();

    sum = t1.addTime(t2);
    std::cout << "Sum of times: ";
    sum.displayTime();

    return 0;
}

/*Output:-
Enter the first time:
Enter hours: 10
Enter minutes: 45
Enter seconds: 30
Enter the second time:
Enter hours: 5
Enter minutes: 20
Enter seconds: 15
First time: 10:45:30
Second time: 5:20:15
Sum of times: 16:5:45

*/