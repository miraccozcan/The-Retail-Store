#include "Hammer.h"

Hammer::Hammer(std::string name, double cost) {
    this->name = name;
    this->cost = cost;
}

double Hammer::GetCost() const {
    return cost;
}

void Hammer::display(std::ostream& os) {
    os.setf(std::ios::fixed);
    os.precision(2);
    os << name << " is a hammer and costs $" << cost << "." << std::endl;
}
