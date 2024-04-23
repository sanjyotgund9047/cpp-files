/*Write a C++ program to display factors of a number.*/

#include <iostream>

using namespace std;

void displayFactors(int num) {
    cout << "Factors of " << num << " are:" << endl;
    for (int i = 1; i <= num; ++i) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    displayFactors(num);

    return 0;
}

/*Output:-
Enter a number: 12
Factors of 12 are:
1 2 3 4 6 12

*/