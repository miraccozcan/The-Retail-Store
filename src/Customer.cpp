#include "Customer.h"
#include "RetailStore.h"

Customer::Customer(std::string name, double cash, RetailStore* store)
    : name(name), cash(cash), toolbox("Toolbox"), groceryBag("Grocery Bag"), store(store) {}

void Customer::addTool(ToolIf* tool) {
    toolbox.AddTool(*tool);
}

void Customer::addGrocery(GroceryIf* grocery) {
    groceryBag.AddGrocery(*grocery);
}

double Customer::calculateTotalCost() const {
    double toolCost = toolbox.getTotalCost();  // Use getter method
    double groceryCost = groceryBag.getTotalCost();  // Use getter method
    double gst = toolCost * 0.14;  // Tools are taxable
    return toolCost + gst + groceryCost;
}

void Customer::pay() {
    double totalCost = calculateTotalCost();
    if (cash >= totalCost) {
        cash -= totalCost;
        store->addRevenue(totalCost);
        store->addCustomerSpending(totalCost);
        store->addToolRevenue(toolbox.getTotalCost());  // Use getter method
        store->addGroceryRevenue(groceryBag.getTotalCost());  // Use getter method
    }
    else {
        std::cout << "Insufficient funds!" << std::endl;
    }
}

void Customer::displayCart() const {
    std::cout << name << "'s Shopping Cart:" << std::endl;
    toolbox.display(std::cout);
    groceryBag.display(std::cout);
    std::cout << "Total cost: $" << calculateTotalCost() << std::endl;
}

std::string Customer::getName() const {
    return name;
}

double Customer::getCash() const {
    return cash;
}
