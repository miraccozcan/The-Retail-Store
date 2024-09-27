#ifndef GROCERYIF_H
#define GROCERYIF_H

#include <iostream>

class GroceryIf {
public:
    virtual double GetCost() const = 0;
    virtual void display(std::ostream& os) = 0;
    virtual ~GroceryIf() = default;  // Ensure proper cleanup
};

#endif
