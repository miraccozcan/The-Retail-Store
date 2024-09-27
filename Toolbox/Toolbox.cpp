//Toolbox.cpp - full code for the toolbox. This needs to be broken into the appropriate files

#include <iostream>
#include <string>//getline
#include <vector>

using namespace std;

class ToolIf {
public:
	virtual double GetCost() const = 0;
	virtual void display(std::ostream& os) = 0;
};

class Hammer : public ToolIf {
	std::string name;
	double cost;
public:
	Hammer(std::string name, double cost) {
		this->name = name;
		this->cost = cost;
	}
	double GetCost() const {
		return cost;
	}
	void display(std::ostream& os) {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << name << " is a hammer and costs $" << cost << "." << std::endl;
	}
};

class Screwdriver : public ToolIf {
	std::string name;
	double cost;
public:
	Screwdriver(std::string name, double cost) {
		this->name = name;
		this->cost = cost;
	}
	double GetCost() const {
		return cost;
	}
	void display(std::ostream& os) {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << name << " is a screwdriver and costs $" << cost << "." << std::endl;
	}
};

ToolIf* CreateTool() {
	ToolIf* tool = nullptr;
	int select = 0;
	string name;
	double cost;
	do {
		cout << endl;
		cout << "Enter 1 for a hammer, or" << endl;
		cout << "Enter 2 for a screwdriver." << endl;
		cout << "Selection: ";
		cin >> select;
		cin.ignore(1000, '\n');
		switch (select) {
		case 1:
			cout << "What is the hammer's name? ";
			getline(cin, name);
			cout << "How much does this hammer cost? $";
			cin >> cost;
			tool = new Hammer(name, cost);
			break;
		case 2:
			cout << "What is the screwdriver's name? ";
			getline(cin, name);
			cout << "How much does this screwdriver cost? $";
			cin >> cost;
			tool = new Screwdriver(name, cost);
			break;
		default:
			cout << "Invalid selection, try again!" << endl;
		}
	} while (select < 1 || select>2);//repeat for an invalid selection

	return tool;
}

const int MAX_TOOLS = 4;

class Toolbox {
	std::string name;
	double totalCost;
	//	ToolIf* item[MAX_TOOLS];
	std::vector<ToolIf*> item;
	int numItems;
public:
	Toolbox(std::string name) {
		this->name = name;
		numItems = 0;
		totalCost = 0.0;
	}
	bool AddTool(ToolIf& tool) {
		int ret = true;
		if (numItems < MAX_TOOLS) {
			//			item[numItems] = &tool;
			item.push_back(&tool);
			++numItems;
			totalCost += tool.GetCost();
		}
		else {
			ret = false;
		}
		return ret;
	}
	void display(std::ostream& os) {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << std::endl;
		os << name << " is a toolbox with the following items:" << std::endl;
		for (int i = 0; i < numItems; ++i) {//one can treat a vector similar to an array
			item[i]->display(os);
		}
		os << "The total cost of these items is $" << totalCost << std::endl << std::endl;
	}
};

std::ostream& operator<<(std::ostream& os, Toolbox& toolbox) {
	toolbox.display(os);
	return os;
}

const int NUM_TOOLS = 2;

int main() {
	Toolbox toolbox("Data Processing Support");
	ToolIf* tool[NUM_TOOLS];

	for (int i = 0; i < NUM_TOOLS; ++i) {
		tool[i] = CreateTool();
		bool ret = toolbox.AddTool(*tool[i]);
		if (!ret) cout << "Unable to add the tool!" << endl;
	}
	cout << toolbox;

	for (int i = 0; i < NUM_TOOLS; ++i) delete tool[i];

	return 0;
}