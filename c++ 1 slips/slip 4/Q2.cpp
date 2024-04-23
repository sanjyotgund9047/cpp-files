/*Write a C++ program to create a class which contains two dimensional integer array of size m*n
Write a member function to display transpose of entered matrix.(Use Dynamic Constructor for
allocating memory and Destructor to free memory of an object). */

#include <iostream>

class Matrix {
private:
    int **arr;
    int m, n;

public:
    // Dynamic constructor to allocate memory for the matrix
    Matrix(int rows, int cols) : m(rows), n(cols) {
        arr = new int*[m];
        for (int i = 0; i < m; ++i) {
            arr[i] = new int[n];
        }
    }

    // Destructor to free dynamically allocated memory
    ~Matrix() {
        for (int i = 0; i < m; ++i) {
            delete [] arr[i];
        }
        delete [] arr;
    }

    // Member function to input elements of the matrix
    void input() {
        std::cout << "Enter elements of the matrix:" << std::endl;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> arr[i][j];
            }
        }
    }

    // Member function to display the transpose of the matrix
    void displayTranspose() {
        std::cout << "Transpose of the matrix:" << std::endl;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int m, n;

    // Input number of rows and columns for the matrix
    std::cout << "Enter number of rows: ";
    std::cin >> m;
    std::cout << "Enter number of columns: ";
    std::cin >> n;

    // Create a Matrix object with dynamic memory allocation
    Matrix matrix(m, n);

    // Input elements of the matrix
    matrix.input();

    // Display the transpose of the matrix
    matrix.displayTranspose();

    return 0;
}

/*Output
Enter number of rows: 2
Enter number of columns: 3
Enter elements of the matrix:
1 2 3
4 5 6
Transpose of the matrix:
1 4
2 5
3 6
*/