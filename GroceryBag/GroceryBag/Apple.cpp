#include "Apple.h"

Apple::Apple(std::string name, double cost, double calories) {
    this->name = name;
    this->cost = cost;
    this->calories = calories;
}

double Apple::GetCost() const {
    return cost;
}

void Apple::display(std::ostream& os) {
    os.setf(std::ios::fixed);
    os.precision(2);
    os << name << " is an apple. It has " << calories << " calories and costs $" << cost << "." << std::endl;
}
