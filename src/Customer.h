#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "../Toolbox/Toolbox/Toolbox.h"
#include "../GroceryBag/GroceryBag/GroceryBag.h"

class RetailStore;

class Customer {
    std::string name;
    double cash;
    Toolbox toolbox;
    GroceryBag groceryBag;
    RetailStore* store;
public:
    Customer(std::string name, double cash, RetailStore* store);
    
    void addTool(ToolIf* tool);
    void addGrocery(GroceryIf* grocery);
    double calculateTotalCost() const;
    void pay();
    void displayCart() const;

    std::string getName() const;
    double getCash() const;
};

#endif
