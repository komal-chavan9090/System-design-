#ifndef CART_H
#define CART_H
#include "product.h"
#include <vector>

class Cart {
private:
    vector<pair<Product*, int>> cartItems;

public:
    void addToCart(Product* p, int quantity) {
        if (quantity > p->getQuantity()) {
            cout << "Not enough stock available for " << p->getProductName() << endl;
        } else {
            cartItems.push_back({p, quantity});
        }
    }

    vector<pair<Product*, int>> getItems() { return cartItems; }

    double getTotalAmount() {
        double total = 0;
        for (auto item : cartItems) {
            total += item.first->getPrice() * item.second;
        }
        return total;
    }
};
namespace sample{
    void get(){
        cout<<"Hiii this is cart";
    }
}
#endif
