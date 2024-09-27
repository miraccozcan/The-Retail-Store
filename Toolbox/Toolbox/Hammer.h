#ifndef HAMMER_H
#define HAMMER_H

#include "ToolIf.h"
#include <string>

class Hammer : public ToolIf {
    std::string name;
    double cost;
public:
    Hammer(std::string name, double cost);
    double GetCost() const override;
    void display(std::ostream& os) override;
};

#endif
