#ifndef TOOLIF_H
#define TOOLIF_H

#include <iostream>

class ToolIf {
public:
    virtual double GetCost() const = 0;
    virtual void display(std::ostream& os) = 0;
    virtual ~ToolIf() = default;  // Ensure proper cleanup
};

#endif
