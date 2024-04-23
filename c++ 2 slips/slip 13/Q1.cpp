/*Write a C++ program to implement a class ‘student’ to overload following functions as follows:
a. int maximum(int, int) – returns the maximum score of two students
b. int maximum(int *a, int arraylength) – returns the maximum score from an array ‘a’ */

#include <iostream>

class student {
public:
    // Function to find the maximum score between two students
    int maximum(int score1, int score2) {
        return (score1 > score2) ? score1 : score2;
    }

    // Function to find the maximum score from an array
    int maximum(int *a, int arraylength) {
        int maxScore = a[0];
        for (int i = 1; i < arraylength; ++i) {
            if (a[i] > maxScore) {
                maxScore = a[i];
            }
        }
        return maxScore;
    }
};

int main() {
    student s;
    
    // Test case for maximum between two scores
    int score1 = 85, score2 = 90;
    std::cout << "Maximum score between " << score1 << " and " << score2 << " is: " << s.maximum(score1, score2) << std::endl;

    // Test case for maximum from an array
    int scores[] = {78, 92, 85, 88, 95};
    int arrayLength = sizeof(scores) / sizeof(scores[0]);
    std::cout << "Maximum score from the array is: " << s.maximum(scores, arrayLength) << std::endl;

    return 0;
}

/*Output:-
Maximum score between 85 and 90 is: 90
Maximum score from the array is: 95
*/