/* Create a class Fraction that contains two data members as numerator and denominator.
Write a C++ program to overload following operators
a. ++ Unary (pre and post both)
b. << and >> Overload as friend functions*/

#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {}

    // Unary pre-increment operator (++frac)
    Fraction& operator++() {
        numerator += denominator;
        return *this;
    }

    // Unary post-increment operator (frac++)
    Fraction operator++(int) {
        Fraction temp = *this;
        numerator += denominator;
        return temp;
    }

    // Friend function to overload stream insertion operator (<<)
    friend ostream& operator<<(ostream& os, const Fraction& frac);

    // Friend function to overload stream extraction operator (>>)
    friend istream& operator>>(istream& is, Fraction& frac);
};

// Definition of stream insertion operator (<<)
ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

// Definition of stream extraction operator (>>)
istream& operator>>(istream& is, Fraction& frac) {
    cout << "Enter numerator: ";
    is >> frac.numerator;
    cout << "Enter denominator: ";
    is >> frac.denominator;
    return is;
}

int main() {
    Fraction f1(2, 3);
    Fraction f2;

    cout << "Enter a fraction (numerator/denominator): ";
    cin >> f2;

    cout << "Fraction f1: " << f1 << endl;
    cout << "Fraction f2: " << f2 << endl;

    cout << "Applying pre-increment operator (++f1): " << ++f1 << endl;
    cout << "Applying post-increment operator (f2++): " << f2++ << endl;

    cout << "Fraction f1 after pre-increment: " << f1 << endl;
    cout << "Fraction f2 after post-increment: " << f2 << endl;

    return 0;
}

/*
Output:-
Enter a fraction (numerator/denominator): 3 4
Fraction f1: 2/3
Fraction f2: 3/4
Applying pre-increment operator (++f1): 8/3
Applying post-increment operator (f2++): 3/4
Fraction f1 after pre-increment: 8/3
Fraction f2 after post-increment: 7/4

*/