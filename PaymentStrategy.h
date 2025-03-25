#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H
#include <iostream>
using namespace std;

class PaymentStrategy {
public:
    virtual string pay(double amount) = 0;
};

class CreditCardPayment : public PaymentStrategy {
public:
    string pay(double amount) override {
        return "Credit Card payment successful for amount: " + to_string(amount) + " Rs.";
    }
};

class Cash : public PaymentStrategy {
public:
    string pay(double amount) override {
        return "Cash payment successful for amount: " + to_string(amount) + " Rs.";
    }
};

class DigitalWalletPayment : public PaymentStrategy {
public:
    string pay(double amount) override {
        return "Digital Wallet payment successful for amount: " + to_string(amount) + " Rs.";
    }
};
#endif
