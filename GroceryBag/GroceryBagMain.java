import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

interface GroceryIf {
    double getCost();

    void display();
}

class Apple implements GroceryIf {
    private String name;
    private double cost;
    private double calories;

    public Apple(String name, double cost, double calories) {
        this.name = name;
        this.cost = cost;
        this.calories = calories;
    }

    @Override
    public double getCost() {
        return cost;
    }

    @Override
    public void display() {
        System.out.printf("%s is an apple. It has %.2f calories and costs $%.2f.%n", name, calories, cost);
    }
}

class Orange implements GroceryIf {
    private String name;
    private double cost;
    private double calories;

    public Orange(String name, double cost, double calories) {
        this.name = name;
        this.cost = cost;
        this.calories = calories;
    }

    @Override
    public double getCost() {
        return cost;
    }

    @Override
    public void display() {
        System.out.printf("%s is an orange. It has %.2f calories and costs $%.2f.%n", name, calories, cost);
    }
}

class GroceryBag {
    private String name;
    private double totalCost;
    private List<GroceryIf> items;
    private static final int MAX_GROCERIES = 4;

    public GroceryBag(String name) {
        this.name = name;
        this.totalCost = 0.0;
        this.items = new ArrayList<>();
    }

    public boolean addGrocery(GroceryIf grocery) {
        if (items.size() < MAX_GROCERIES) {
            items.add(grocery);
            totalCost += grocery.getCost();
            return true;
        } else {
            return false;
        }
    }

    public void display() {
        System.out.println();
        System.out.println(name + " is a grocery bag with the following items:");
        for (GroceryIf item : items) {
            item.display();
        }
        System.out.printf("The total cost of these items is $%.2f%n%n", totalCost);
    }
}

public class GroceryBagMain {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        GroceryBag groceryBag = new GroceryBag("Data Processing Support");
        final int NUM_GROCERIES = 2;
        GroceryIf[] groceries = new GroceryIf[NUM_GROCERIES];

        for (int i = 0; i < NUM_GROCERIES; i++) {
            groceries[i] = createGrocery(scanner);
            boolean added = groceryBag.addGrocery(groceries[i]);
            if (!added) {
                System.out.println("Unable to add the grocery!");
            }
        }

        groceryBag.display();

        for (int i = 0; i < NUM_GROCERIES; i++) {
            groceries[i] = null; // Free the memory
        }
    }

    public static GroceryIf createGrocery(Scanner scanner) {
        GroceryIf grocery = null;
        int select = 0;
        String name;
        double cost;
        double calories;
        do {
            System.out.println();
            System.out.println("Enter 1 for an apple, or");
            System.out.println("Enter 2 for an orange.");
            System.out.print("Selection: ");
            select = scanner.nextInt();
            scanner.nextLine();
            switch (select) {
                case 1:
                    System.out.print("What is the apple's name? ");
                    name = scanner.nextLine();
                    System.out.print("How many calories does this apple have? ");
                    calories = scanner.nextDouble();
                    System.out.print("How much does this apple cost? $");
                    cost = scanner.nextDouble();
                    grocery = new Apple(name, cost, calories);
                    break;
                case 2:
                    System.out.print("What is the orange's name? ");
                    name = scanner.nextLine();
                    System.out.print("How many calories does this orange have? ");
                    calories = scanner.nextDouble();
                    System.out.print("How much does this orange cost? $");
                    cost = scanner.nextDouble();
                    grocery = new Orange(name, cost, calories);
                    break;
                default:
                    System.out.println("Invalid selection, try again!");
            }
        } while (select < 1 || select > 2); // Repeat for an invalid selection

        return grocery;
    }
}
