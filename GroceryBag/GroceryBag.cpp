//GroceryBag.cpp - full code for the grocery bag. This needs to be broken into the appropriate files

#include <iostream>
#include <string>//getline
#include <vector>

using namespace std;

class GroceryIf {
public:
	virtual double GetCost() const = 0;
	virtual void display(std::ostream& os) = 0;
};

class Apple : public GroceryIf {
	std::string name;
	double cost;
	double calories;
public:
	Apple(std::string name, double cost, double calories) {
		this->name = name;
		this->cost = cost;
		this->calories = calories;
	}
	double GetCost() const {
		return cost;
	}
	void display(std::ostream& os) {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << name << " is a apple. It has " << calories << " calories and costs $" << cost << "." << std::endl;
	}
};

class Orange : public GroceryIf {
	std::string name;
	double cost;
	double calories;
public:
	Orange(std::string name, double cost, double calories) {
		this->name = name;
		this->cost = cost;
		this->calories = calories;
	}
	double GetCost() const {
		return cost;
	}
	void display(std::ostream& os) {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << name << " is a orange. It has " << calories << " calories and costs $" << cost << "." << std::endl;
	}
};

GroceryIf* CreateGrocery() {
	GroceryIf* grocery = nullptr;
	int select = 0;
	string name;
	double cost;
	double calories;
	do {
		cout << endl;
		cout << "Enter 1 for a apple, or" << endl;
		cout << "Enter 2 for a orange." << endl;
		cout << "Selection: ";
		cin >> select;
		cin.ignore(1000, '\n');
		switch (select) {
		case 1:
			cout << "What is the apple's name? ";
			getline(cin, name);
			cout << "How many calories does this apple have? ";
			cin >> calories;
			cout << "How much does this apple cost? $";
			cin >> cost;
			grocery = new Apple(name, cost, calories);
			break;
		case 2:
			cout << "What is the orange's name? ";
			getline(cin, name);
			cout << "How many calories does this orange have? ";
			cin >> calories;
			cout << "How much does this orange cost? $";
			cin >> cost;
			grocery = new Orange(name, cost, calories);
			break;
		default:
			cout << "Invalid selection, try again!" << endl;
		}
	} while (select < 1 || select>2);//repeat for an invalid selection

	return grocery;
}

const int MAX_GROCERIES = 4;

class GroceryBag {
	std::string name;
	double totalCost;
	//	GroceryIf* item[MAX_GROCERIES];
	std::vector<GroceryIf*> item;
	int numItems;
public:
	GroceryBag(std::string name) {
		this->name = name;
		numItems = 0;
		totalCost = 0.0;
	}
	bool AddGrocery(GroceryIf& grocery) {
		int ret = true;
		if (numItems < MAX_GROCERIES) {
			//			item[numItems] = &grocery;
			item.push_back(&grocery);
			++numItems;
			totalCost += grocery.GetCost();
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
		os << name << " is a grocery bag with the following items:" << std::endl;
		for (int i = 0; i < numItems; ++i) {//one can treat a vector similar to an array
			item[i]->display(os);
		}
		os << "The total cost of these items is $" << totalCost << std::endl << std::endl;
	}
};

std::ostream& operator<<(std::ostream& os, GroceryBag& grocerybag) {
	grocerybag.display(os);
	return os;
}

const int NUM_GROCERIES = 2;

int main() {
	GroceryBag grocerybag("Data Processing Support");
	GroceryIf* grocery[NUM_GROCERIES];

	for (int i = 0; i < NUM_GROCERIES; ++i) {
		grocery[i] = CreateGrocery();
		bool ret = grocerybag.AddGrocery(*grocery[i]);
		if (!ret) cout << "Unable to add the grocery!" << endl;
	}
	cout << grocerybag;

	for (int i = 0; i < NUM_GROCERIES; ++i) delete grocery[i];

	return 0;
}