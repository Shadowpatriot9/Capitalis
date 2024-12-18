#include "product.h"
#include <iostream>

// Constructor
product::product(std::string product_name, int product_cost, int product_revenue)
    : name(product_name), cost(product_cost), revenue(product_revenue) {}

// Getters
std::string product::get_name() const { return name; }
int product::get_cost() const { return cost; }
int product::get_revenue() const { return revenue; }

// Display Method
void product::display() const {
    std::cout << "Product: " << name << "\n"
              << "Cost: " << cost << "\n"
              << "Revenue: " << revenue << "\n";
}
