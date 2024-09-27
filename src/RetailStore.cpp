#include "RetailStore.h"
#include <iostream>

RetailStore::RetailStore() : totalRevenue(0.0), toolRevenue(0.0), groceryRevenue(0.0) {}

void RetailStore::addCustomer(Customer* customer) {
    customers.push_back(customer);
}

void RetailStore::addRevenue(double amount) {
    totalRevenue += amount;
}

void RetailStore::addToolRevenue(double amount) {
    toolRevenue += amount;
}

void RetailStore::addGroceryRevenue(double amount) {
    groceryRevenue += amount;
}

void RetailStore::addCustomerSpending(double amount) {
    totalRevenue += amount;
}

void RetailStore::displayStatistics() const {
    double averageSpending = totalRevenue / customers.size();
    double toolPercentage = (toolRevenue / totalRevenue) * 100.0;
    double groceryPercentage = (groceryRevenue / totalRevenue) * 100.0;
    
    std::cout << "Store Statistics:" << std::endl;
    std::cout << "Total Revenue: $" << totalRevenue << std::endl;
    std::cout << "Average Spending per Customer: $" << averageSpending << std::endl;
    std::cout << "Percentage of Revenue from Tools: " << toolPercentage << "%" << std::endl;
    std::cout << "Percentage of Revenue from Groceries: " << groceryPercentage << "%" << std::endl;
}
