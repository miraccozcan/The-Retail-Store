#include "Screwdriver.h"

Screwdriver::Screwdriver(std::string name, double cost) {
    this->name = name;
    this->cost = cost;
}

double Screwdriver::GetCost() const {
    return cost;
}

void Screwdriver::display(std::ostream& os) {
    os.setf(std::ios::fixed);
    os.precision(2);
    os << name << " is a screwdriver and costs $" << cost << "." << std::endl;
}
