// =======================================
// Introduction
// =======================================

/*
 Brief: This is to be used as a daily item where a block of code is completed incremently with a minimum requirement of one line of code not including an adjustment to a single line of code.
 Author: Grayden Scovil
 Date of Origin: 12/06/2024


 Requirements:
 - The daily adjustment must be at minimum of a single line of code in any language but has no maximum value.
 - It must not integere with the program in a way that makes the code not function as intended (aka, dont break it otherwise you will loose encouragement).
 - There is no time requirement.
 - Thats all I got for the moment.
 - There will be no carry over. If a day is missed, the day following will have the same minimum of a single line of code is not to be compounded.
 */

// ========================================
// Dependencies
// ========================================

#include <iostream>
#include <string>
#include <vector>
#include "product.h"

// Expression Simplification
using namespace std;

// ========================================
// Global
// ========================================

// Global Variables
int money_current = 100;
int money_increment {};
const int money_game_win = 1000;
int option {};
int turn_counter {1};
vector<string> products;

// ========================================
// Classes
// ========================================

// Building Object
class building {
    private:
        string name;
        string type;
    
    public:
    //Constructor
    building(string building_name, string building_type) {
        name = building_name;
        type = building_type;
    }
    
    string get_name_b() const {
        return name;
    }
    string get_type_b() const {
        return type;
    }
    
};

// ========================================
// Functions
// ========================================

// Per Turn Menu Function
void overview() {
    cout << "------------------------" << "\n\n";
    cout << "Turn Number: " << turn_counter << "\n";
    cout << "Current Money: $" << money_current << "\n";
    cout << "Revenue per turn: $" << money_increment << "\n";
    cout << "Expenses per turn: $" << "***" << "\n";
    
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

// Buy Menu Function
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
        cout << "\n" << "------------------------" << "\n";

        // Product Variables
        string name;
        int revenue = 5;
        int cost = 10;
        vector<product> products;
       
        // Product Input
        cout << "Cost of New Product: $" << cost << "\n";
        cout << "\n" << "Enter Name of Product: ";
        cin >> name;
        
        // Product Creation
        product product_1(name, cost, revenue);
        product_1.display(); // ***remove once product function verified gtg***
        
        // Product Results
        money_increment += revenue; // Product revenue incremeter based on type of product bought
        cout << name << " bought successfully.";
        money_current -= cost;
        cout << "\n" << "Current Money: $" << money_current << "\n\n";
        products.push_back(product_1); // Add product purchased to all products owned by user
        
    } else if (option_buy == "B") {
        cout << "\n" << "------------------------" << "\n";

        // Building Variables
        string name;
        string type;
        
        // Building Input
        cout << "Type Options: " << "\n" << "- Sales" << "\n" << "- Marketing ***" "\n\n";
        cout << "Type?: ";
        cin >> type;
        cout << "Name?: ";
        cin >> name;
        
        // Building Creation
        building building_sales(name, type);
        
        // Building Results
        cout << "\n" << name << " bought." << "\n";
        cout << type << " - type." << "\n\n";
        
    } else {
        cout << "Invalid Option, Try Again" << "\n\n";
        
    }
}

// Sell Menu Function
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
        if (money_current >= money_game_win) {
            cout << "**************************" << "\n";
            cout << "Congratulations!" << "\n";
            cout << "You have past $" << money_game_win << " and have won the game by reaching: $" << money_current << "!" << "\n";
            cout << "**************************" << "\n";
            cout << "\n" << "Would you like to continue playing? (Y/N): ";
            
            // Continue Game Option (optional)
            string game_end_selector {};
            cin >> game_end_selector;
            if (game_end_selector == "Y") {
                cout << "\n";
                continue;
            } else if (game_end_selector == "N") {
                cout << "Ending Game..." << "\n\n";
                break;
            }
        }
        
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
