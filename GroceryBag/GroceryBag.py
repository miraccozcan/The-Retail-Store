
from abc import ABC, abstractmethod

class GroceryIf(ABC):
    @abstractmethod
    def get_cost(self):
        pass
    
    @abstractmethod
    def display(self):
        pass

class Apple(GroceryIf):
    def __init__(self, name, cost, calories):
        self.name = name
        self.cost = cost
        self.calories = calories
    
    def get_cost(self):
        return self.cost
    
    def display(self):
        print(f"{self.name} is an apple. It has {self.calories} calories and costs ${self.cost:.2f}.")

class Orange(GroceryIf):
    def __init__(self, name, cost, calories):
        self.name = name
        self.cost = cost
        self.calories = calories
    
    def get_cost(self):
        return self.cost
    
    def display(self):
        print(f"{self.name} is an orange. It has {self.calories} calories and costs ${self.cost:.2f}.")

def create_grocery():
    grocery = None
    select = 0
    name = ""
    cost = 0.0
    calories = 0.0
    
    while select < 1 or select > 2:
        print()
        print("Enter 1 for an apple, or")
        print("Enter 2 for an orange.")
        select = int(input("Selection: "))
        
        if select == 1:
            name = input("What is the apple's name? ")
            calories = float(input("How many calories does this apple have? "))
            cost = float(input("How much does this apple cost? $"))
            grocery = Apple(name, cost, calories)
        elif select == 2:
            name = input("What is the orange's name? ")
            calories = float(input("How many calories does this orange have? "))
            cost = float(input("How much does this orange cost? $"))
            grocery = Orange(name, cost, calories)
        else:
            print("Invalid selection, try again!")
    
    return grocery

class GroceryBag:
    def __init__(self, name):
        self.name = name
        self.total_cost = 0.0
        self.items = []
        self.num_items = 0
    
    def add_grocery(self, grocery):
        if self.num_items < 4:
            self.items.append(grocery)
            self.num_items += 1
            self.total_cost += grocery.get_cost()
            return True
        return False
    
    def display(self):
        print()
        print(f"{self.name} is a grocery bag with the following items:")
        for item in self.items:
            item.display()
        print(f"The total cost of these items is ${self.total_cost:.2f}\n")

if __name__ == "__main__":
    NUM_GROCERIES = 2
    grocery_bag = GroceryBag("Data Processing Support")
    groceries = []

    for _ in range(NUM_GROCERIES):
        grocery = create_grocery()
        ret = grocery_bag.add_grocery(grocery)
        if not ret:
            print("Unable to add the grocery!")
        else:
            groceries.append(grocery)

    grocery_bag.display()

    for grocery in groceries:
        grocery = None
