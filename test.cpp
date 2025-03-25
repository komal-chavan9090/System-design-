#include <iostream>
#include "product.h"
#include "cart.h"
#include "customer.h"
#include "bill.h"

using namespace std;
using namespace sample;

int main() {
    vector<Product*> products = {
        new Product(1, "Laptop", 50000, 10, "Electronics"),
        new Product(2, "Mobile", 20000, 20, "Electronics"),
        new Product(3, "Shirt", 1000, 50, "Clothing"),
        new Product(4, "Trousers", 1500, 30, "Clothing"),
        new Product(5, "Shoes", 2000, 40, "Footwear"),
        new Product(6, "Slippers", 500, 60, "Footwear"),
        new Product(7, "Rice", 50, 100, "Grocery"),
        new Product(8, "Wheat", 30, 100, "Grocery")
    };

    // cout<<sample::get();

    cout << "Enter Your Name: ";
    string name;
    cin >> name;
    Customer customer(name);
    Cart cart;

    cout << "\nProducts Available:\n";
    for (auto p : products) {
        cout << p->getProductId() << ". " << p->getProductName() << " - " 
             << p->getPrice() << " Rs\n";
    }
    int id;
    cout << "Enter product id you want to buy: ";
    cin >> id;
    cout<<"Enter quantity: ";
    int quantity;
    cin>>quantity;
    cart.addToCart(products[id - 1], quantity);

    while (true) {
        cout << "Enter Product ID to Buy (0 to Stop): ";
        int id, quantity;
        cin >> id;
        if (id == 0) break;

        cout << "Enter Quantity: ";
        cin >> quantity;

        cart.addToCart(products[id - 1], quantity);
    }

    Bill bill(&cart, &customer);
    bill.generateBill();

    return 0;
}
