/*Design a base class Product(Product _Id, Product _Name, Price). Derive a class Discount
(Discount_In_Percentage) from Product. A customer buys n Products. Calculate total price,
total discount and display bill using appropriate manipulators. */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Product {
protected:
    int Product_Id;
    std::string Product_Name;
    double Price;

public:
    Product(int id, const std::string& name, double price)
        : Product_Id(id), Product_Name(name), Price(price) {}

    virtual ~Product() {} // Virtual destructor

    // Function to calculate the price after discount
    virtual double getPriceAfterDiscount() const {
        return Price;
    }

    // Function to display product details
    virtual void display() const {
        std::cout << std::setw(5) << Product_Id << std::setw(20) << Product_Name << std::setw(10) << Price;
    }
};

class Discount : public Product {
private:
    double Discount_In_Percentage;

public:
    Discount(int id, const std::string& name, double price, double discount)
        : Product(id, name, price), Discount_In_Percentage(discount) {}

    // Overriding function to calculate the price after discount
    double getPriceAfterDiscount() const override {
        return Price - (Price * Discount_In_Percentage / 100);
    }

    // Overriding function to display product details
    void display() const override {
        Product::display();
        std::cout << std::setw(15) << Discount_In_Percentage << "%" << std::setw(15) << getPriceAfterDiscount() << std::endl;
    }
};

int main() {
    int n;
    std::cout << "Enter the number of products: ";
    std::cin >> n;

    std::vector<Product*> products;

    // Enter details of n products
    for (int i = 0; i < n; ++i) {
        int id;
        std::string name;
        double price;
        double discount;

        std::cout << "Enter details for product " << i + 1 << ":" << std::endl;
        std::cout << "ID: ";
        std::cin >> id;
        std::cout << "Name: ";
        std::cin.ignore();
        getline(std::cin, name);
        std::cout << "Price: ";
        std::cin >> price;
        std::cout << "Discount (%): ";
        std::cin >> discount;

        Product* product = new Discount(id, name, price, discount);
        products.push_back(product);
    }

    // Display bill header
    std::cout << "\nBill:\n";
    std::cout << std::setw(5) << "ID" << std::setw(20) << "Name" << std::setw(10) << "Price" << std::setw(15) << "Discount %" << std::setw(15) << "Final Price" << std::endl;

    // Display details of all products and calculate total price
    double total_price = 0;
    for (const auto& product : products) {
        product->display();
        std::cout << std::endl;
        total_price += product->getPriceAfterDiscount();
    }

    // Display total price
    std::cout << "\nTotal Price: " << total_price << std::endl;

    // Free memory allocated for products
    for (auto& product : products) {
        delete product;
    }

    return 0;
}


/*Output:-
Enter the number of products: 2
Enter details for product 1:
ID: 101
Name: Banana
Price: 50
Discount (%): 10
Enter details for product 2:
ID: 102
Name: Jelly
Price: 100
Discount (%): 20

Bill:
   ID                Name     Price     Discount %    Final Price
  101              Banana        50             10%             45

  102               Jelly       100             20%             80


Total Price: 125
*/