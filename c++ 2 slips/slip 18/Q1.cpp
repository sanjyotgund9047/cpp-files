/*Write a C++ program to calculate following series:
(1) + (1+2) + (1+2+3) + (1+2+3+4) + ... +(1+2+3+4+...+n)*/

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int sum = 0;
    int innerSum = 0;
    for (int i = 1; i <= n; ++i) {
        innerSum += i; // Calculate inner sum for each term
        sum += innerSum; // Add the inner sum to the total sum
    }

    cout << "Sum of the series: " << sum << endl;

    return 0;
}

/*Output:-
Enter the value of n: 5
Sum of the series: 35
*/