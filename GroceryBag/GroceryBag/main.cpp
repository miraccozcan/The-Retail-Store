#include "GroceryFactory.h"
#include "GroceryBag.h"
#include <iostream>

int main() {
    GroceryBag grocerybag("Data Processing Support");
    const int NUM_GROCERIES = 2;
    GroceryIf* groceries[NUM_GROCERIES];

    for (int i = 0; i < NUM_GROCERIES; ++i) {
        int selection;
        std::string name;
        double cost;
        double calories;

        do {
            std::cout << "\nEnter 1 for an apple, or\n";
            std::cout << "Enter 2 for an orange.\n";
            std::cout << "Selection: ";
            std::cin >> selection;
            std::cin.ignore(1000, '\n');

            if (selection == 1 || selection == 2) {
                std::cout << "Enter the name of the grocery: ";
                getline(std::cin, name);
                std::cout << "Enter the number of calories: ";
                std::cin >> calories;
                std::cout << "Enter the cost of the grocery: $";
                std::cin >> cost;
                groceries[i] = GroceryFactory::CreateGrocery(selection, name, cost, calories);
            } else {
                std::cout << "Invalid selection, try again!" << std::endl;
            }
        } while (selection < 1 || selection > 2);

        bool ret = grocerybag.AddGrocery(*groceries[i]);
        if (!ret) std::cout << "Unable to add the grocery!" << std::endl;
    }

    std::cout << grocerybag;

    return 0;
}
