#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class product {
private:
    std::string name;
    int cost;
    int revenue;

public:
    product(std::string product_name, int product_cost, int product_revenue);
    std::string get_name() const;
    int get_cost() const;
    int get_revenue() const;
    void display() const;
};

#endif
