/*Create a class Matrix and Write a C++ program to perform following functions:
a. To accept a Matrix
b. To display a Matrix
c. Overload unary minus ‘–‘ operator to calculate transpose of a Matrix
d. Overload binary multiplication '*’ operator to calculate multiplication of two matrices
*/

#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> mat;
    int rows;
    int cols;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        // Resize matrix to r x c and initialize with zeros
        mat.resize(rows, std::vector<int>(cols, 0));
    }

    // Function to accept a matrix
    void acceptMatrix() {
        std::cout << "Enter elements of the matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> mat[i][j];
            }
        }
    }

    // Function to display a matrix
    void displayMatrix() const {
        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Overloading unary minus operator to calculate transpose of a matrix
    Matrix operator-() const {
        Matrix result(cols, rows);
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                result.mat[i][j] = mat[j][i];
            }
        }
        return result;
    }

    // Overloading binary multiplication operator to calculate multiplication of two matrices
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Error: Matrices cannot be multiplied!" << std::endl;
            return Matrix(0, 0);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    int rows1, cols1, rows2, cols2;

    // Accept dimensions of first matrix
    std::cout << "Enter dimensions of first matrix (rows columns): ";
    std::cin >> rows1 >> cols1;

    // Create and accept first matrix
    Matrix mat1(rows1, cols1);
    mat1.acceptMatrix();

    // Display first matrix
    std::cout << "\nFirst ";
    mat1.displayMatrix();

    // Calculate and display transpose of first matrix
    std::cout << "\nTranspose of First ";
    (-mat1).displayMatrix();

    // Accept dimensions of second matrix
    std::cout << "\nEnter dimensions of second matrix (rows columns): ";
    std::cin >> rows2 >> cols2;

    // Create and accept second matrix
    Matrix mat2(rows2, cols2);
    mat2.acceptMatrix();

    // Display second matrix
    std::cout << "\nSecond ";
    mat2.displayMatrix();

    // Calculate and display transpose of second matrix
    std::cout << "\nTranspose of Second ";
    (-mat2).displayMatrix();

    // Perform matrix multiplication and display result
    std::cout << "\nResult of matrix multiplication:" << std::endl;
    (mat1 * mat2).displayMatrix();

    return 0;
}

/*Output
Enter dimensions of first matrix (rows columns): 2 2
Enter elements of the matrix:
1 2
3 4

First Matrix:
1 2 
3 4 

Transpose of First Matrix:
1 3 
2 4 

Enter dimensions of second matrix (rows columns): 2 2
Enter elements of the matrix:
5 6
7 8

Second Matrix:
5 6 
7 8 

Transpose of Second Matrix:
5 7 
6 8 

Result of matrix multiplication:
19 22 
43 50

*/