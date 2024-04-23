/*A book (ISBN) and CD (data capacity) are both types of media (id, title) objects. A person buys
10 media items each of which can be either book or CD. Display the list of all books and CD’s
bought. Define the classes and appropriate member functions to accept and display data. Use
pointers and concept of polymorphism (Virtual Function) */
#include <iostream>
#include <string>
#include <vector>

class Media {
protected:
    int id;
    std::string title;

public:
    Media(int id, const std::string& title) : id(id), title(title) {}

    // Virtual function to display media details
    virtual void display() const {
        std::cout << "ID: " << id << ", Title: " << title;
    }
};

class Book : public Media {
private:
    std::string isbn;

public:
    Book(int id, const std::string& title, const std::string& isbn) : Media(id, title), isbn(isbn) {}

    // Override display function to include ISBN
    void display() const override {
        Media::display();
        std::cout << ", ISBN: " << isbn << std::endl;
    }
};

class CD : public Media {
private:
    std::string dataCapacity;

public:
    CD(int id, const std::string& title, const std::string& dataCapacity) : Media(id, title), dataCapacity(dataCapacity) {}

    // Override display function to include data capacity
    void display() const override {
        Media::display();
        std::cout << ", Data Capacity: " << dataCapacity << std::endl;
    }
};

int main() {
    std::vector<Media*> mediaList;

    // Add some books and CDs to the media list
    mediaList.push_back(new Book(1, "The Catcher in the Rye", "9780316769488"));
    mediaList.push_back(new CD(2, "Abbey Road", "700 MB"));
    mediaList.push_back(new Book(3, "To Kill a Mockingbird", "9780061120084"));
    mediaList.push_back(new CD(4, "Dark Side of the Moon", "800 MB"));
    // Add more media items as needed...

    // Display the list of all books and CDs bought
    std::cout << "List of all books and CDs bought:" << std::endl;
    for (const auto& media : mediaList) {
        media->display();
    }

    // Clean up allocated memory
    for (auto& media : mediaList) {
        delete media;
    }

    return 0;
}
