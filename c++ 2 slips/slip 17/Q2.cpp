/*Create a class Fraction containing data members as Numerator and Denominator.
Write a program to overload operators ++ , -- and * to increment, decrement a Fraction and
multiply two Fraction respectively. (Use constructor to initialize values of an object)*/

#include <iostream>

using namespace std;

class Fraction {
private:
    int Numerator;
    int Denominator;

public:
    // Constructor to initialize the Fraction
    Fraction(int numerator = 0, int denominator = 1) : Numerator(numerator), Denominator(denominator) {}

    // Overload ++ operator to increment Fraction
    Fraction operator++() {
        Numerator += Denominator;
        return *this;
    }

    // Overload -- operator to decrement Fraction
    Fraction operator--() {
        Numerator -= Denominator;
        return *this;
    }

    // Overload * operator to multiply two Fractions
    Fraction operator*(const Fraction& other) {
        int newNumerator = Numerator * other.Numerator;
        int newDenominator = Denominator * other.Denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Display the Fraction
    void display() const {
        cout << Numerator << "/" << Denominator;
    }
};

int main() {
    // Create two Fraction objects
    Fraction frac1(2, 3);
    Fraction frac2(3, 4);

    // Display original fractions
    cout << "Fraction 1: ";
    frac1.display();
    cout << endl;

    cout << "Fraction 2: ";
    frac2.display();
    cout << endl;

    // Increment Fraction 1 and display
    cout << "After incrementing Fraction 1: ";
    (++frac1).display();
    cout << endl;

    // Decrement Fraction 2 and display
    cout << "After decrementing Fraction 2: ";
    (--frac2).display();
    cout << endl;

    // Multiply Fraction 1 and Fraction 2 and display
    cout << "Result of multiplying Fraction 1 and Fraction 2: ";
    (frac1 * frac2).display();
    cout << endl;

    return 0;
}

/*Output:-
Fraction 1: 2/3
Fraction 2: 3/4
After incrementing Fraction 1: 8/3
After decrementing Fraction 2: -9/4
Result of multiplying Fraction 1 and Fraction 2: -27/16
*/