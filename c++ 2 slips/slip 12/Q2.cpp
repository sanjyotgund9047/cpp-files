/*Write a C++ program to create a class which contains single dimensional integer array of
given size. Define member function to display median of a given array. (Use Dynamic
Constructor to allocate and Destructor to free memory of an object).*/

#include <iostream>
#include <algorithm>

using namespace std;

class ArrayWithMedian {
private:
    int* arr;
    int size;

public:
    // Dynamic constructor to allocate memory for array
    ArrayWithMedian(int size) {
        this->size = size;
        arr = new int[size];
    }

    // Destructor to free memory
    ~ArrayWithMedian() {
        delete[] arr;
    }

    // Function to input elements into the array
    void inputElements() {
        cout << "Enter " << size << " elements:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

    // Function to display the median of the array
    void displayMedian() {
        // Sort the array
        sort(arr, arr + size);

        // Calculate the median
        double median;
        if (size % 2 == 0) {
            median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        } else {
            median = arr[size / 2];
        }

        cout << "Median of the array: " << median << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Create object of ArrayWithMedian class
    ArrayWithMedian array(size);

    // Input elements into the array
    array.inputElements();

    // Display the median of the array
    array.displayMedian();

    return 0;
}
/*Output:-
Enter the size of the array: 5
Enter 5 elements:
4
7
2
9
5
Median of the array: 5

*/