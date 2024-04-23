/*Create a base class Media. Derive two different classes Book (Book_id, Book_name,
Publication, Author, Book_price) and CD (CD_title, CD_price) from Media. Write a program
to accept and display information of both Book and CD. (Use pure virtual function) */

#include <iostream>
#include <string>

using namespace std;

// Base class Media
class Media {
public:
    // Pure virtual function to accept information
    virtual void acceptInfo() = 0;

    // Pure virtual function to display information
    virtual void displayInfo() = 0;
};

// Derived class Book from Media
class Book : public Media {
private:
    int Book_id;
    string Book_name;
    string Publication;
    string Author;
    float Book_price;

public:
    // Implementation of acceptInfo for Book
    void acceptInfo() override {
        cout << "Enter Book ID: ";
        cin >> Book_id;
        cout << "Enter Book Name: ";
        cin.ignore();
        getline(cin, Book_name);
        cout << "Enter Publication: ";
        getline(cin, Publication);
        cout << "Enter Author: ";
        getline(cin, Author);
        cout << "Enter Book Price: ";
        cin >> Book_price;
    }

    // Implementation of displayInfo for Book
    void displayInfo() override {
        cout << "Book ID: " << Book_id << endl;
        cout << "Book Name: " << Book_name << endl;
        cout << "Publication: " << Publication << endl;
        cout << "Author: " << Author << endl;
        cout << "Book Price: " << Book_price << endl;
    }
};

// Derived class CD from Media
class CD : public Media {
private:
    string CD_title;
    float CD_price;

public:
    // Implementation of acceptInfo for CD
    void acceptInfo() override {
        cout << "Enter CD Title: ";
        cin.ignore();
        getline(cin, CD_title);
        cout << "Enter CD Price: ";
        cin >> CD_price;
    }

    // Implementation of displayInfo for CD
    void displayInfo() override {
        cout << "CD Title: " << CD_title << endl;
        cout << "CD Price: " << CD_price << endl;
    }
};

int main() {
    // Creating objects of Book and CD
    Book book;
    CD cd;

    // Accepting and displaying information of Book
    cout << "Enter information for Book:" << endl;
    book.acceptInfo();
    cout << "\nInformation of Book:" << endl;
    book.displayInfo();

    // Accepting and displaying information of CD
    cout << "\nEnter information for CD:" << endl;
    cd.acceptInfo();
    cout << "\nInformation of CD:" << endl;
    cd.displayInfo();

    return 0;
}

/*Output:-
Enter information for Book:
Enter Book ID: 101
Enter Book Name: The Catcher in the Rye
Enter Publication: Little, Brown and Company
Enter Author: J.D. Salinger
Enter Book Price: 12.99

Information of Book:
Book ID: 101
Book Name: The Catcher in the Rye
Publication: Little, Brown and Company
Author: J.D. Salinger
Book Price: 12.99

Enter information for CD:
Enter CD Title: Abbey Road
Enter CD Price: 14.99

Information of CD:
CD Title: Abbey Road
CD Price: 14.99
*/