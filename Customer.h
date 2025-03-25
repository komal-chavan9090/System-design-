#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;

class Customer {
    string name;

public:
    Customer(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
};
#endif
