#ifndef TOOLBOX_H
#define TOOLBOX_H

#include "ToolIf.h"
#include <vector>
#include <string>
#include <iostream>

class Toolbox {
    std::string name;
    double totalCost;
    std::vector<ToolIf*> items;
    int numItems;
public:
    Toolbox(std::string name);
    bool AddTool(ToolIf& tool);
    void display(std::ostream& os) const;  // Mark as const
    double getTotalCost() const;  // Getter method
    ~Toolbox();
};

std::ostream& operator<<(std::ostream& os, const Toolbox& toolbox);

#endif
