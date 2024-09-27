#include "GroceryFactory.h"

GroceryIf* GroceryFactory::CreateGrocery(int selection, const std::string& name, double cost, double calories) {
    switch (selection) {
        case 1: return new Apple(name, cost, calories);
        case 2: return new Orange(name, cost, calories);
        default: return nullptr;
    }
}
