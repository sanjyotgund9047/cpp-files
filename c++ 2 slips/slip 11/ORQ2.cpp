/*Create a base class Conversion. Derive three different classes Weight (Gram, Kilogram),
Volume (Milliliter, Liter), Currency (Rupees, Paise) from Conversion class. Write a program
to perform read, convert and display operations. (Use Pure virtual function) */

#include <iostream>
#include <string>

using namespace std;

// Base class Conversion
class Conversion {
public:
    // Pure virtual function for reading input
    virtual void readInput() = 0;

    // Pure virtual function for converting
    virtual void convert() = 0;

    // Pure virtual function for displaying result
    virtual void displayResult() const = 0;
};

// Derived class Weight
class Weight : public Conversion {
protected:
    double value;

public:
    // Function to read weight input
    void readInput() override {
        cout << "Enter weight value: ";
        cin >> value;
    }

    // Function to convert weight
    virtual void convert() override = 0;

    // Function to display weight result
    virtual void displayResult() const override = 0;
};

// Derived class Gram
class Gram : public Weight {
public:
    // Function to convert weight to gram
    void convert() override {
        // No conversion needed for Gram
    }

    // Function to display weight in gram
    void displayResult() const override {
        cout << "Weight in Gram: " << value << endl;
    }
};

// Derived class Kilogram
class Kilogram : public Weight {
public:
    // Function to convert weight to kilogram
    void convert() override {
        value /= 1000; // Convert gram to kilogram
    }

    // Function to display weight in kilogram
    void displayResult() const override {
        cout << "Weight in Kilogram: " << value << endl;
    }
};

// Derived class Volume
class Volume : public Conversion {
protected:
    double value;

public:
    // Function to read volume input
    void readInput() override {
        cout << "Enter volume value: ";
        cin >> value;
    }

    // Function to convert volume
    virtual void convert() override = 0;

    // Function to display volume result
    virtual void displayResult() const override = 0;
};

// Derived class Milliliter
class Milliliter : public Volume {
public:
    // Function to convert volume to milliliter
    void convert() override {
        // No conversion needed for Milliliter
    }

    // Function to display volume in milliliter
    void displayResult() const override {
        cout << "Volume in Milliliter: " << value << endl;
    }
};

// Derived class Liter
class Liter : public Volume {
public:
    // Function to convert volume to liter
    void convert() override {
        value /= 1000; // Convert milliliter to liter
    }

    // Function to display volume in liter
    void displayResult() const override {
        cout << "Volume in Liter: " << value << endl;
    }
};

// Derived class Currency
class Currency : public Conversion {
protected:
    double value;

public:
    // Function to read currency input
    void readInput() override {
        cout << "Enter currency value: ";
        cin >> value;
    }

    // Function to convert currency
    virtual void convert() override = 0;

    // Function to display currency result
    virtual void displayResult() const override = 0;
};

// Derived class Rupees
class Rupees : public Currency {
public:
    // Function to convert currency to rupees
    void convert() override {
        // No conversion needed for Rupees
    }

    // Function to display currency in rupees
    void displayResult() const override {
        cout << "Currency in Rupees: " << value << endl;
    }
};

// Derived class Paise
class Paise : public Currency {
public:
    // Function to convert currency to paise
    void convert() override {
        value *= 100; // Convert rupees to paise
    }

    // Function to display currency in paise
    void displayResult() const override {
        cout << "Currency in Paise: " << value << endl;
    }
};

int main() {
    // Demonstration for Weight Conversion
    cout << "Weight Conversion:" << endl;
    Gram gram;
    gram.readInput();
    gram.convert();
    gram.displayResult();

    Kilogram kilogram;
    kilogram.readInput();
    kilogram.convert();
    kilogram.displayResult();

    // Demonstration for Volume Conversion
    cout << "\nVolume Conversion:" << endl;
    Milliliter milliliter;
    milliliter.readInput();
    milliliter.convert();
    milliliter.displayResult();

    Liter liter;
    liter.readInput();
    liter.convert();
    liter.displayResult();

    // Demonstration for Currency Conversion
    cout << "\nCurrency Conversion:" << endl;
    Rupees rupees;
    rupees.readInput();
    rupees.convert();
    rupees.displayResult();

    Paise paise;
    paise.readInput();
    paise.convert();
    paise.displayResult();

    return 0;
}

/*Output:-
Weight Conversion:
Enter weight value: 1500
Weight in Gram: 1500
Enter weight value: 1500
Weight in Kilogram: 1.5

Volume Conversion:
Enter volume value: 2500
Volume in Milliliter: 2500
Enter volume value: 2500
Volume in Liter: 2.5

Currency Conversion:
Enter currency value: 500
Currency in Rupees: 500
Enter currency value: 500
Currency in Paise: 50000

*/