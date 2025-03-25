#ifndef BILL_H
#define BILL_H
#include "cart.h"
#include "customer.h"
#include "paymentstrategy.h"

class Bill {
private:
    Cart* cart;
    Customer* customer;
    PaymentStrategy* payment;
    double total = 0;
    double discount = 0;

public:
    Bill(Cart* c, Customer* cust) {
        this->cart = c;
        this->customer = cust;
        this->total = cart->getTotalAmount();
    }

    void applyDiscount() {
        if (total > 1000) {
            discount = total * 0.05;
            cout << "Applied 5% discount: -" << discount << " Rs\n";
        }

        double groceryBill = 0;
        for (auto item : cart->getItems()) {
            if (item.first->getCategory() == "Grocery") {
                groceryBill += item.first->getPrice() * item.second;
            }
        }
        if (groceryBill > 1000) {
            double groceryDiscount = groceryBill * 0.15;
            discount += groceryDiscount;
            cout << "Applied 15% discount on grocery items: -" << groceryDiscount << " Rs\n";
        }
    }

    void generateBill() {
        applyDiscount();
        double finalAmount = total - discount;

        cout << "\n========= Invoice =========\n";
        cout << "Customer Name: " << customer->getName() << endl;
        cout << "Items Purchased:\n";
        for (auto item : cart->getItems()) {
            cout << item.first->getProductName() << " x" << item.second 
                 << " - " << item.first->getPrice() * item.second << " Rs\n";
        }
        cout << "Total Amount: " << total << " Rs\n";
        cout << "Discount: " << discount << " Rs\n";
        cout << "Final Amount: " << finalAmount << " Rs\n";

        // Choose Payment Method
        cout << "\nChoose Payment Method:\n1. Credit Card\n2. Cash\n3. Digital Wallet\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                payment = new CreditCardPayment();
                break;
            case 2:
                payment = new Cash();
                break;
            case 3:
                payment = new DigitalWalletPayment();
                break;
            default:
                cout << "Invalid choice, defaulting to Cash.\n";
                payment = new Cash();
        }

        cout << payment->pay(finalAmount) << endl;
    }
};
#endif
