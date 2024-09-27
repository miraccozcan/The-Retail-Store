#ifndef ORANGE_H
#define ORANGE_H

#include "GroceryIf.h"
#include <string>

class Orange : public GroceryIf {
    std::string name;
    double cost;
    double calories;
public:
    Orange(std::string name, double cost, double calories);
    double GetCost() const override;
    void display(std::ostream& os) override;
};

#endif
