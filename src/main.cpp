#include "Customer.h"
#include "RetailStore.h"
#include "../Toolbox/Toolbox/ToolFactory.h"  // Include for ToolFactory
#include "../GroceryBag/GroceryBag/GroceryFactory.h"  // Include for GroceryFactory


int main() {
    RetailStore store;
    
    // Create three customers
    Customer customer1("Alice", 100.0, &store);
    Customer customer2("Bob", 150.0, &store);
    Customer customer3("Charlie", 200.0, &store);
    
    // Simulate shopping
    customer1.addTool(ToolFactory::CreateTool(1, "Hammer A", 25.0));
    customer1.addGrocery(GroceryFactory::CreateGrocery(1, "Apple A", 2.5, 95.0));
    customer1.pay();
    customer1.displayCart();
    
    customer2.addTool(ToolFactory::CreateTool(2, "Screwdriver B", 15.0));
    customer2.addGrocery(GroceryFactory::CreateGrocery(2, "Orange B", 3.0, 80.0));
    customer2.pay();
    customer2.displayCart();
    
    customer3.addTool(ToolFactory::CreateTool(1, "Hammer C", 30.0));
    customer3.addGrocery(GroceryFactory::CreateGrocery(1, "Apple C", 2.0, 90.0));
    customer3.pay();
    customer3.displayCart();
    
    // Display store statistics
    store.displayStatistics();
    
    return 0;
}
