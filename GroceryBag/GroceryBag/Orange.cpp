#include "Orange.h"

Orange::Orange(std::string name, double cost, double calories) {
    this->name = name;
    this->cost = cost;
    this->calories = calories;
}

double Orange::GetCost() const {
    return cost;
}

void Orange::display(std::ostream& os) {
    os.setf(std::ios::fixed);
    os.precision(2);
    os << name << " is an orange. It has " << calories << " calories and costs $" << cost << "." << std::endl;
}
