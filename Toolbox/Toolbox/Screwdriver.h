#ifndef SCREWDRIVER_H
#define SCREWDRIVER_H

#include "ToolIf.h"
#include <string>

class Screwdriver : public ToolIf {
    std::string name;
    double cost;
public:
    Screwdriver(std::string name, double cost);
    double GetCost() const override;
    void display(std::ostream& os) override;
};

#endif
