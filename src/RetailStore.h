#ifndef RETAILSTORE_H
#define RETAILSTORE_H

#include <vector>
#include "Customer.h"

class RetailStore {
    std::vector<Customer*> customers;
    double totalRevenue;
    double toolRevenue;
    double groceryRevenue;
public:
    RetailStore();
    
    void addCustomer(Customer* customer);
    void addRevenue(double amount);
    void addToolRevenue(double amount);
    void addGroceryRevenue(double amount);
    void addCustomerSpending(double amount);
    
    void displayStatistics() const;
};

#endif
