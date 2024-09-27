import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Toolbox {
    private String name;
    private double totalCost;
    private List<ToolIf> items;
    private int numItems;

    public Toolbox(String name) {
        this.name = name;
        this.totalCost = 0.0;
        this.items = new ArrayList<>();
        this.numItems = 0;
    }

    public boolean addTool(ToolIf tool) {
        if (numItems < 4) {
            items.add(tool);
            numItems++;
            totalCost += tool.getCost();
            return true;
        }
        return false;
    }

    public void display() {
        System.out.println();
        System.out.println(name + " is a toolbox with the following items:");
        for (ToolIf item : items) {
            item.display();
        }
        System.out.printf("The total cost of these items is $%.2f%n%n", totalCost);
    }

    public static void main(String[] args) {
        Toolbox toolbox = new Toolbox("Data Processing Support");
        ToolIf[] tools = new ToolIf[2];
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < tools.length; i++) {
            ToolIf tool = createTool(scanner);
            boolean ret = toolbox.addTool(tool);
            if (!ret) {
                System.out.println("Unable to add the tool!");
            }
            tools[i] = tool;
        }

        toolbox.display();

        for (ToolIf tool : tools) {
            tool = null;
        }
    }

    private static ToolIf createTool(Scanner scanner) {
        ToolIf tool = null;
        int select;
        String name;
        double cost;

        do {
            System.out.println();
            System.out.println("Enter 1 for a hammer, or");
            System.out.println("Enter 2 for a screwdriver.");
            System.out.print("Selection: ");
            select = scanner.nextInt();
            scanner.nextLine();

            switch (select) {
                case 1:
                    System.out.print("What is the hammer's name? ");
                    name = scanner.nextLine();
                    System.out.print("How much does this hammer cost? $");
                    cost = scanner.nextDouble();
                    scanner.nextLine();
                    tool = new Hammer(name, cost);
                    break;
                case 2:
                    System.out.print("What is the screwdriver's name? ");
                    name = scanner.nextLine();
                    System.out.print("How much does this screwdriver cost? $");
                    cost = scanner.nextDouble();
                    scanner.nextLine();
                    tool = new Screwdriver(name, cost);
                    break;
                default:
                    System.out.println("Invalid selection, try again!");
            }
        } while (select < 1 || select > 2); // Repeat for an invalid selection

        return tool;
    }
}

interface ToolIf {
    double getCost();
    void display();
}

class Hammer implements ToolIf {
    private String name;
    private double cost;

    public Hammer(String name, double cost) {
        this.name = name;
        this.cost = cost;
    }

    @Override
    public double getCost() {
        return cost;
    }

    @Override
    public void display() {
        System.out.printf("%s is a hammer and costs $%.2f.%n", name, cost);
    }
}

class Screwdriver implements ToolIf {
    private String name;
    private double cost;

    public Screwdriver(String name, double cost) {
        this.name = name;
        this.cost = cost;
    }

    @Override
    public double getCost() {
        return cost;
    }

    @Override
    public void display() {
        System.out.printf("%s is a screwdriver and costs $%.2f.%n", name, cost);
    }
}
