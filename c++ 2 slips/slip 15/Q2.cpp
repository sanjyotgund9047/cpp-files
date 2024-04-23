/*Create a base class Conversion. Derive three different classes Weight (Gram, Kilogram), Volume
(Milliliter, Liter), Currency (Rupees, Paise) from Conversion class. Write a program to perform
read, convert and display operations. (Use Pure virtual function) */

#include <iostream>
#include <string>

using namespace std;

class Conversion {
public:
    virtual void read() = 0;
    virtual void convert() = 0;
    virtual void display() = 0;
};

class Weight : public Conversion {
protected:
    double value;
public:
    Weight() : value(0) {}
    virtual void read() {
        cout << "Enter weight: ";
        cin >> value;
    }
};

class Gram : public Weight {
public:
    virtual void convert() {
        // No conversion needed for grams
    }
    virtual void display() {
        cout << "Weight in Grams: " << value << endl;
    }
};

class Kilogram : public Weight {
public:
    virtual void convert() {
        value *= 1000; // Conversion from kilograms to grams
    }
    virtual void display() {
        cout << "Weight in Kilograms: " << value << endl;
    }
};

class Volume : public Conversion {
protected:
    double value;
public:
    Volume() : value(0) {}
    virtual void read() {
        cout << "Enter volume: ";
        cin >> value;
    }
};

class Milliliter : public Volume {
public:
    virtual void convert() {
        // No conversion needed for milliliters
    }
    virtual void display() {
        cout << "Volume in Milliliters: " << value << endl;
    }
};

class Liter : public Volume {
public:
    virtual void convert() {
        value *= 1000; // Conversion from liters to milliliters
    }
    virtual void display() {
        cout << "Volume in Liters: " << value << endl;
    }
};

class Currency : public Conversion {
protected:
    double value;
public:
    Currency() : value(0) {}
    virtual void read() {
        cout << "Enter currency amount: ";
        cin >> value;
    }
};

class Rupees : public Currency {
public:
    virtual void convert() {
        // No conversion needed for rupees
    }
    virtual void display() {
        cout << "Amount in Rupees: " << value << endl;
    }
};

class Paise : public Currency {
public:
    virtual void convert() {
        value *= 100; // Conversion from rupees to paise
    }
    virtual void display() {
        cout << "Amount in Paise: " << value << endl;
    }
};

int main() {
    Gram gram;
    gram.read();
    gram.convert();
    gram.display();

    Kilogram kilogram;
    kilogram.read();
    kilogram.convert();
    kilogram.display();

    Milliliter milliliter;
    milliliter.read();
    milliliter.convert();
    milliliter.display();

    Liter liter;
    liter.read();
    liter.convert();
    liter.display();

    Rupees rupees;
    rupees.read();
    rupees.convert();
    rupees.display();

    Paise paise;
    paise.read();
    paise.convert();
    paise.display();

    return 0;
}

/*Output:-
Enter weight: 0.5
Weight in Grams: 0.5
Enter weight: 0.5
Weight in Kilograms: 500
Enter volume: 1.5
Volume in Milliliters: 1.5
Enter volume: 1.5
Volume in Liters: 1500
Enter currency amount: 10
Amount in Rupees: 10
Enter currency amount: 10
Amount in Paise: 1000
*/