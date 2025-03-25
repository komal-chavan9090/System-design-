#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

class Product {
    int product_id;
    string product_name;
    double price;
    int quantity;
    string category;

public:
    Product(int id, string product_name, double price, int quantity, string category) {
        this->product_id = id;
        this->product_name = product_name;
        this->price = price;
        this->quantity = quantity;
        this->category = category;
    }

    string getProductName() { return product_name; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }
    int getProductId() { return product_id; }
    string getCategory() { return category; }
};
#endif
