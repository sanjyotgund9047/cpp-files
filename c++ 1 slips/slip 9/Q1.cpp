/*Write a C++ program to create a class Item with data members Item_code, Item_name, Item_Price.
Write member functions to accept and display item information and also display number of objects
created for a class. (Use Static data member and Static member function)*/

#include <iostream>
#include <string>

class Item {
private:
    int item_code;
    std::string item_name;
    double item_price;
    static int num_objects;

public:
    Item() {
        num_objects++;
    }

    void acceptItem() {
        std::cout << "Enter item code: ";
        std::cin >> item_code;
        std::cin.ignore(); // Ignore the newline character
        std::cout << "Enter item name: ";
        std::getline(std::cin, item_name);
        std::cout << "Enter item price: ";
        std::cin >> item_price;
    }

    void displayItem() {
        std::cout << "Item Code: " << item_code << std::endl;
        std::cout << "Item Name: " << item_name << std::endl;
        std::cout << "Item Price: " << item_price << std::endl;
    }

    static void displayNumObjects() {
        std::cout << "Number of objects created: " << num_objects << std::endl;
    }
};

int Item::num_objects = 0;

int main() {
    Item item1, item2;

    std::cout << "Enter details for item 1:" << std::endl;
    item1.acceptItem();

    std::cout << "\nEnter details for item 2:" << std::endl;
    item2.acceptItem();

    std::cout << "\nDetails of item 1:" << std::endl;
    item1.displayItem();

    std::cout << "\nDetails of item 2:" << std::endl;
    item2.displayItem();

    Item::displayNumObjects();

    return 0;
}

/*
Output:-
Enter details for item 1:
Enter item code: 101
Enter item name: Book
Enter item price: 25.5

Enter details for item 2:
Enter item code: 102
Enter item name: Pen
Enter item price: 5.75

Details of item 1:
Item Code: 101
Item Name: Book
Item Price: 25.5

Details of item 2:
Item Code: 102
Item Name: Pen
Item Price: 5.75

Number of objects created: 2
*/