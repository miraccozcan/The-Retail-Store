using System;
using System.Collections.Generic;

namespace GroceryBagApp
{
    public interface IGrocery
    {
        double GetCost();
        void Display();
    }

    public class Apple : IGrocery
    {
        private string name;
        private double cost;
        private double calories;

        public Apple(string name, double cost, double calories)
        {
            this.name = name;
            this.cost = cost;
            this.calories = calories;
        }

        public double GetCost()
        {
            return cost;
        }

        public void Display()
        {
            Console.WriteLine($"{name} is an apple. It has {calories} calories and costs ${cost:f2}.");
        }
    }

    public class Orange : IGrocery
    {
        private string name;
        private double cost;
        private double calories;

        public Orange(string name, double cost, double calories)
        {
            this.name = name;
            this.cost = cost;
            this.calories = calories;
        }

        public double GetCost()
        {
            return cost;
        }

        public void Display()
        {
            Console.WriteLine($"{name} is an orange. It has {calories} calories and costs ${cost:f2}.");
        }
    }

    public class GroceryBag
    {
        private string name;
        private double totalCost;
        private List<IGrocery> items;
        private int numItems;

        public GroceryBag(string name)
        {
            this.name = name;
            totalCost = 0.0;
            items = new List<IGrocery>();
            numItems = 0;
        }

        public bool AddGrocery(IGrocery grocery)
        {
            if (numItems < 4)
            {
                items.Add(grocery);
                numItems++;
                totalCost += grocery.GetCost();
                return true;
            }

            return false;
        }

        public void Display()
        {
            Console.WriteLine();
            Console.WriteLine($"{name} is a grocery bag with the following items:");

            foreach (var item in items)
            {
                item.Display();
            }

            Console.WriteLine($"The total cost of these items is ${totalCost:f2}\n");
        }
    }

    class Program
    {
        static IGrocery CreateGrocery()
        {
            IGrocery grocery = null;
            int select = 0;
            string name;
            double cost;
            double calories;

            do
            {
                Console.WriteLine();
                Console.WriteLine("Enter 1 for an apple, or");
                Console.WriteLine("Enter 2 for an orange.");
                Console.Write("Selection: ");
                select = Convert.ToInt32(Console.ReadLine());

                switch (select)
                {
                    case 1:
                        Console.Write("What is the apple's name? ");
                        name = Console.ReadLine();
                        Console.Write("How many calories does this apple have? ");
                        calories = Convert.ToDouble(Console.ReadLine());
                        Console.Write("How much does this apple cost? $");
                        cost = Convert.ToDouble(Console.ReadLine());
                        grocery = new Apple(name, cost, calories);
                        break;
                    case 2:
                        Console.Write("What is the orange's name? ");
                        name = Console.ReadLine();
                        Console.Write("How many calories does this orange have? ");
                        calories = Convert.ToDouble(Console.ReadLine());
                        Console.Write("How much does this orange cost? $");
                        cost = Convert.ToDouble(Console.ReadLine());
                        grocery = new Orange(name, cost, calories);
                        break;
                    default:
                        Console.WriteLine("Invalid selection, try again!");
                        break;
                }
            } while (select < 1 || select > 2);

            return grocery;
        }

        static void Main(string[] args)
        {
            const int NUM_GROCERIES = 2;
            GroceryBag groceryBag = new GroceryBag("Data Processing Support");
            IGrocery[] groceries = new IGrocery[NUM_GROCERIES];

            for (int i = 0; i < NUM_GROCERIES; ++i)
            {
                groceries[i] = CreateGrocery();
                bool ret = groceryBag.AddGrocery(groceries[i]);

                if (!ret)
                {
                    Console.WriteLine("Unable to add the grocery!");
                }
            }

            groceryBag.Display();

            for (int i = 0; i < NUM_GROCERIES; ++i)
            {
                groceries[i] = null;
            }

            Console.ReadLine();
        }
    }
}
