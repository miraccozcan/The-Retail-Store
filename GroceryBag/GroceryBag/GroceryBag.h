#ifndef GROCERYBAG_H
#define GROCERYBAG_H

#include "GroceryIf.h"
#include <vector>
#include <string>
#include <iostream>

class GroceryBag {
    std::string name;
    double totalCost;
    std::vector<GroceryIf*> items;
    int numItems;
public:
    GroceryBag(std::string name);
    bool AddGrocery(GroceryIf& grocery);
    void display(std::ostream& os) const;  // Mark as const
    double getTotalCost() const;  // Getter method
    ~GroceryBag();
};

std::ostream& operator<<(std::ostream& os, const GroceryBag& grocerybag);

#endif
