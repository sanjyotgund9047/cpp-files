/*Create a class Book containing Book_name, author and Price as a data member and write
necessary member functions for the following (use function overloading).
a. To Accept and display the Book Information.
b. Display book details of a given author
c. Display book details of specific price*/
#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string bookName;
    std::string author;
    float price;

public:
    // Parameterized constructor
    Book(const std::string& name, const std::string& auth, float pr) : bookName(name), author(auth), price(pr) {}

    // Function to display book information
    void display() const {
        std::cout << "Book Name: " << bookName << std::endl;
        std::cout << "Author: " << author << std::endl;
        std::cout << "Price: " << price << std::endl;
    }

    // Function to display book details of a given author
    void display(const std::string& auth) const {
        if (author == auth) {
            display();
        }
    }

    // Function to display book details of specific price
    void display(float pr) const {
        if (price == pr) {
            display();
        }
    }
};

int main() {
    // Create a vector to store books
    std::vector<Book> books;

    // Add books to the vector
    books.push_back(Book("Book1", "Author1", 20.0));
    books.push_back(Book("Book2", "Author2", 15.0));
    books.push_back(Book("Book3", "Author1", 25.0));
    books.push_back(Book("Book4", "Author3", 30.0));

    // Display all books
    std::cout << "All Books:" << std::endl;
    for (const auto& book : books) {
        book.display();
        std::cout << std::endl;
    }

    // Display book details of a given author
    std::cout << "Books by Author1:" << std::endl;
    for (const auto& book : books) {
        book.display("Author1");
        std::cout << std::endl;
    }

    // Display book details of specific price
    std::cout << "Books with price 20.0:" << std::endl;
    for (const auto& book : books) {
        book.display(20.0);
        std::cout << std::endl;
    }

    return 0;
}

/*Output

All Books:
Book Name: Book1
Author: Author1
Price: 20

Book Name: Book2
Author: Author2
Price: 15

Book Name: Book3
Author: Author1
Price: 25

Book Name: Book4
Author: Author3
Price: 30

Books by Author1:
Book Name: Book1
Author: Author1
Price: 20

Book Name: Book3
Author: Author1
Price: 25

Books with price 20.0:
Book Name: Book1
Author: Author1
Price: 20
*/