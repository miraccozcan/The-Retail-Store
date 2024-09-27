#include "ToolFactory.h"

ToolIf* ToolFactory::CreateTool(int selection, const std::string& name, double cost) {
    switch (selection) {
        case 1: return new Hammer(name, cost);
        case 2: return new Screwdriver(name, cost);
        default: return nullptr;
    }
}
