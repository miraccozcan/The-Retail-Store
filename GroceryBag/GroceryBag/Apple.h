#ifndef APPLE_H
#define APPLE_H

#include "GroceryIf.h"
#include <string>

class Apple : public GroceryIf {
    std::string name;
    double cost;
    double calories;
public:
    Apple(std::string name, double cost, double calories);
    double GetCost() const override;
    void display(std::ostream& os) override;
};

#endif
