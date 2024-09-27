#include "Toolbox.h"

Toolbox::Toolbox(std::string name) : name(name), totalCost(0.0), numItems(0) {}

bool Toolbox::AddTool(ToolIf& tool) {
    const int MAX_TOOLS = 4;
    if (numItems < MAX_TOOLS) {
        items.push_back(&tool);
        ++numItems;
        totalCost += tool.GetCost();
        return true;
    }
    return false;
}

void Toolbox::display(std::ostream& os) const {  // Marked as const
    os.setf(std::ios::fixed);
    os.precision(2);
    os << std::endl << name << " is a toolbox with the following items:" << std::endl;
    for (ToolIf* item : items) {
        item->display(os);
    }
    os << "The total cost of these items is $" << totalCost << std::endl << std::endl;
}

double Toolbox::getTotalCost() const {  // Getter method implementation
    return totalCost;
}

Toolbox::~Toolbox() {
    for (ToolIf* item : items) {
        delete item;
    }
}

std::ostream& operator<<(std::ostream& os, const Toolbox& toolbox) {  // Marked as const
    toolbox.display(os);
    return os;
}
