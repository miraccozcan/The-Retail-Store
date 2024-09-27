#include "GroceryBag.h"

GroceryBag::GroceryBag(std::string name) : name(name), totalCost(0.0), numItems(0) {}

bool GroceryBag::AddGrocery(GroceryIf& grocery) {
    const int MAX_GROCERIES = 4;
    if (numItems < MAX_GROCERIES) {
        items.push_back(&grocery);
        ++numItems;
        totalCost += grocery.GetCost();
        return true;
    }
    return false;
}

void GroceryBag::display(std::ostream& os) const {  // Marked as const
    os.setf(std::ios::fixed);
    os.precision(2);
    os << std::endl << name << " is a grocery bag with the following items:" << std::endl;
    for (GroceryIf* item : items) {
        item->display(os);
    }
    os << "The total cost of these items is $" << totalCost << std::endl << std::endl;
}

double GroceryBag::getTotalCost() const {  // Getter method implementation
    return totalCost;
}

GroceryBag::~GroceryBag() {
    for (GroceryIf* item : items) {
        delete item;
    }
}

std::ostream& operator<<(std::ostream& os, const GroceryBag& grocerybag) {  // Marked as const
    grocerybag.display(os);
    return os;
}
