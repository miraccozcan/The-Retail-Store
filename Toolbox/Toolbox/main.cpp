#include "ToolFactory.h"
#include "Toolbox.h"
#include <iostream>

int main() {
    Toolbox toolbox("Data Processing Support");
    const int NUM_TOOLS = 2;
    ToolIf* tools[NUM_TOOLS];

    for (int i = 0; i < NUM_TOOLS; ++i) {
        int selection;
        std::string name;
        double cost;

        do {
            std::cout << "\nEnter 1 for a hammer, or\n";
            std::cout << "Enter 2 for a screwdriver.\n";
            std::cout << "Selection: ";
            std::cin >> selection;
            std::cin.ignore(1000, '\n');

            if (selection == 1 || selection == 2) {
                std::cout << "Enter the name of the tool: ";
                getline(std::cin, name);
                std::cout << "Enter the cost of the tool: $";
                std::cin >> cost;
                tools[i] = ToolFactory::CreateTool(selection, name, cost);
            } else {
                std::cout << "Invalid selection, try again!" << std::endl;
            }
        } while (selection < 1 || selection > 2);

        bool ret = toolbox.AddTool(*tools[i]);
        if (!ret) std::cout << "Unable to add the tool!" << std::endl;
    }

    std::cout << toolbox;

    return 0;
}
