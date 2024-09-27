#ifndef GROCERYFACTORY_H
#define GROCERYFACTORY_H

#include "GroceryIf.h"
#include "Apple.h"
#include "Orange.h"
#include <string>

class GroceryFactory {
public:
    static GroceryIf* CreateGrocery(int selection, const std::string& name, double cost, double calories);
};

#endif
