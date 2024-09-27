#ifndef TOOLFACTORY_H
#define TOOLFACTORY_H

#include "ToolIf.h"
#include "Hammer.h"
#include "Screwdriver.h"
#include <string>

class ToolFactory {
public:
    static ToolIf* CreateTool(int selection, const std::string& name, double cost);
};

#endif
