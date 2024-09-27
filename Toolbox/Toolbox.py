
from abc import ABC, abstractmethod

class ToolIf(ABC):
    @abstractmethod
    def get_cost(self):
        pass
    
    @abstractmethod
    def display(self):
        pass

class Hammer(ToolIf):
    def __init__(self, name, cost):
        self.name = name
        self.cost = cost
    
    def get_cost(self):
        return self.cost
    
    def display(self):
        print(f"{self.name} is a hammer and costs ${self.cost:.2f}.")

class Screwdriver(ToolIf):
    def __init__(self, name, cost):
        self.name = name
        self.cost = cost
    
    def get_cost(self):
        return self.cost
    
    def display(self):
        print(f"{self.name} is a screwdriver and costs ${self.cost:.2f}.")

def create_tool():
    tool = None
    select = 0
    name = ""
    cost = 0.0
    
    while select < 1 or select > 2:
        print()
        print("Enter 1 for a hammer, or")
        print("Enter 2 for a screwdriver.")
        select = int(input("Selection: "))
        
        if select == 1:
            name = input("What is the hammer's name? ")
            cost = float(input("How much does this hammer cost? $"))
            tool = Hammer(name, cost)
        elif select == 2:
            name = input("What is the screwdriver's name? ")
            cost = float(input("How much does this screwdriver cost? $"))
            tool = Screwdriver(name, cost)
        else:
            print("Invalid selection, try again!")
    
    return tool

class Toolbox:
    def __init__(self, name):
        self.name = name
        self.total_cost = 0.0
        self.items = []
        self.num_items = 0
    
    def add_tool(self, tool):
        if self.num_items < 4:
            self.items.append(tool)
            self.num_items += 1
            self.total_cost += tool.get_cost()
            return True
        return False
    
    def display(self):
        print()
        print(f"{self.name} is a toolbox with the following items:")
        for item in self.items:
            item.display()
        print(f"The total cost of these items is ${self.total_cost:.2f}\n")

if __name__ == "__main__":
    NUM_TOOLS = 2
    toolbox = Toolbox("Data Processing Support")
    tools = []

    for _ in range(NUM_TOOLS):
        tool = create_tool()
        ret = toolbox.add_tool(tool)
        if not ret:
            print("Unable to add the tool!")
        else:
            tools.append(tool)

    toolbox.display()

    for tool in tools:
        tool = None
