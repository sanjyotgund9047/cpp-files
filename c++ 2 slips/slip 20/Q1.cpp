/*Write a C++ program to sort integer and float array elements in ascending order by using
function overloading.*/

#include <iostream>
#include <algorithm>

using namespace std;

// Function to sort integer array in ascending order
void sortArray(int arr[], int size) {
    sort(arr, arr + size);
}

// Function to sort float array in ascending order
void sortArray(float arr[], int size) {
    sort(arr, arr + size);
}

// Function to display integer array
void displayArray(int arr[], int size) {
    cout << "Sorted Integer Array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to display float array
void displayArray(float arr[], int size) {
    cout << "Sorted Float Array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intArr[] = {4, 2, 7, 1, 5};
    float floatArr[] = {3.5, 1.2, 6.7, 2.8, 4.9};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);

    // Sort integer array
    sortArray(intArr, intSize);
    // Display sorted integer array
    displayArray(intArr, intSize);

    // Sort float array
    sortArray(floatArr, floatSize);
    // Display sorted float array
    displayArray(floatArr, floatSize);

    return 0;
}

/*Output:-
Sorted Integer Array:
1 2 4 5 7 
Sorted Float Array:
1.2 2.8 3.5 4.9 6.7 
*/