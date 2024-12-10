// =======================================
// Introduction
// =======================================

// Author: Grayden Scovil
// Date of Origin: 12/06/2024
// Brief: This is to be used as a daily item where a block of code is completed incremently with a minimum requirement of one line of code not including an adjustment to a single line of code.
//
// Requirements:
// - The daily adjustment must be at minimum of a single line of code in any language but has no maximum value.
// - It must not integere with the program in a way that makes the code not function as intended (aka, dont break it otherwise you will loose encouragement).
// - There is no time requirement.
// - Thats all I got for the moment.
// - There will be no carry over. If a day is missed, the day following will have the same minimum of a single line of code is not to be compounded.

// ========================================
// Dependencies
// ========================================

#include <iostream>
#include <string>
#include <vector>

// ========================================
// Global
// ========================================

// Expression Simplification
using std::cout;
using std::cin;
using std::string;
using std::vector;

// Global Variables
int money_current = 10;
int money_increment {};
int option {};
int turn_counter {1};
vector<string> products;

// ========================================
// Classes
// ========================================



// ========================================
// Functions
// ========================================

void overview() {
    cout << "------------------------" << "\n\n";
    cout << "Turn Number: " << turn_counter << "\n";
    cout << "Current Money: $" << money_current << "\n";
    
    // Print each product in the vector
    cout << "Products Owned: \n";
    for (const auto& product : products) {
        cout << "- " << product << "\n";
    }
    cout << "\n";
    
    cout << "------------------------" << "\n\n";
    cout << "What do you want to do?" << "\n";
    cout << "Enter '1' to Buy" << "\n" << "Enter '2' to Sell" << "\n" << "Enter '3' to Exit " << "\n\n" << "Option: ";
    
    // Overview Menu Selection Variable Declaration
    cin >> option;
}

void buy() {
    // Buy Overview Menu
    cout << "\n" << "------------------------" << "\n";
    cout << "\n" << "What would you like to buy?" << "\n\n";
    cout << "Enter 'P' for Product" << "\n";
    cout << "Enter 'B' for Building" << "\n";
    cout << "\n" << "Selection: ";
    
    // Buy Selection Variable Declaration
    string option_buy;
    cin >> option_buy;
    
    if (option_buy == "P") { // Product Option
        //
        cout << "\n" << "------------------------" << "\n";

        // Product Cost Logic
        int product_revenue_1 = 3;
        int product_cost_small = 10;
        cout << "Cost of New Product: $" << product_cost_small << "\n";
        
        // Product Details
        string product_1;
        cout << "\n" << "Enter Name of Product: ";
        cin >> product_1;
        cout << product_1 << " bought successfully.";
        
        // Product Purchase Logic
        money_current -= product_cost_small;
        cout << "\n" << "Current Money: $" << money_current << "\n\n";
        money_increment += product_revenue_1; // Product revenue incremeter based on type of product bought
        products.push_back(product_1); // Add product purchased to all products owned by user
        
    }
}

void sell() {
    cout << "sell\n\n";
}

// ========================================
// Main Program
// ========================================

int main () {
    // Intro Tagline
    cout << "================================" << "\n";
    cout << "===== Welcome to Capitalis =====" << "\n";
    cout << "================================" << "\n\n";
    
    while (true) {
        // Overview Menu
        overview();
        
        // Option Selector
        if (option == 1) buy(); // Buy Option
        else if (option == 2) sell(); // Sell Option
        else if (option == 3) break; // Exit Game
        else cout << "not valid"; // No Option
        
        // Game End Checker (win)

        
        // Game End Checker (lose)
        if (money_current <= 0)  {
            cout << "**************************" << "\n";
            cout << "You have run out of money." << "\n" << "Game Over." << "\n";
            cout << "**************************" << "\n\n";
            break;
        }
        
        // End of Turn Actions
        money_current += money_increment;
        turn_counter ++;
        
    }
    return 0;

}

// ========================================
