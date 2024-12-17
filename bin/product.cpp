#include "product.h"
#include <iostream>
using namespace std;

product::product(string product_name, int product_cost, int product_revenue)
    : name(product_name), cost(product_cost), revenue(product_revenue) {}

string product::get_name() const { return name; } // Getter for Cost
int product::get_cost() const { return cost; } // Getter for Revenue
int product::get_revenue() const { return revenue; }

// Display
void product::display() const {
    cout << "Product: " << name << "\n" << "Cost: " << cost << "\n";
}

