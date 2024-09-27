using System;
using System.Collections.Generic;

namespace ToolboxApp
{
    public interface ITool
    {
        double GetCost();
        void Display();
    }

    public class Hammer : ITool
    {
        private string name;
        private double cost;

        public Hammer(string name, double cost)
        {
            this.name = name;
            this.cost = cost;
        }

        public double GetCost()
        {
            return cost;
        }

        public void Display()
        {
            Console.WriteLine($"{name} is a hammer and costs ${cost:f2}.");
        }
    }

    public class Screwdriver : ITool
    {
        private string name;
        private double cost;

        public Screwdriver(string name, double cost)
        {
            this.name = name;
            this.cost = cost;
        }

        public double GetCost()
        {
            return cost;
        }

        public void Display()
        {
            Console.WriteLine($"{name} is a screwdriver and costs ${cost:f2}.");
        }
    }

    public class Toolbox
    {
        private string name;
        private double totalCost;
        private List<ITool> items;
        private int numItems;

        public Toolbox(string name)
        {
            this.name = name;
            totalCost = 0.0;
            items = new List<ITool>();
            numItems = 0;
        }

        public bool AddTool(ITool tool)
        {
            if (numItems < 4)
            {
                items.Add(tool);
                numItems++;
                totalCost += tool.GetCost();
                return true;
            }

            return false;
        }

        public void Display()
        {
            Console.WriteLine();
            Console.WriteLine($"{name} is a toolbox with the following items:");

            foreach (var item in items)
            {
                item.Display();
            }

            Console.WriteLine($"The total cost of these items is ${totalCost:f2}\n");
        }
    }

    class Program
    {
        static ITool CreateTool()
        {
            ITool tool = null;
            int select = 0;
            string name;
            double cost;

            do
            {
                Console.WriteLine();
                Console.WriteLine("Enter 1 for a hammer, or");
                Console.WriteLine("Enter 2 for a screwdriver.");
                Console.Write("Selection: ");
                select = Convert.ToInt32(Console.ReadLine());

                switch (select)
                {
                    case 1:
                        Console.Write("What is the hammer's name? ");
                        name = Console.ReadLine();
                        Console.Write("How much does this hammer cost? $");
                        cost = Convert.ToDouble(Console.ReadLine());
                        tool = new Hammer(name, cost);
                        break;
                    case 2:
                        Console.Write("What is the screwdriver's name? ");
                        name = Console.ReadLine();
                        Console.Write("How much does this screwdriver cost? $");
                        cost = Convert.ToDouble(Console.ReadLine());
                        tool = new Screwdriver(name, cost);
                        break;
                    default:
                        Console.WriteLine("Invalid selection, try again!");
                        break;
                }
            } while (select < 1 || select > 2);

            return tool;
        }

        static void Main(string[] args)
        {
            const int NUM_TOOLS = 2;
            Toolbox toolbox = new Toolbox("Data Processing Support");
            ITool[] tool = new ITool[NUM_TOOLS];

            for (int i = 0; i < NUM_TOOLS; i++)
            {
                tool[i] = CreateTool();
                bool ret = toolbox.AddTool(tool[i]);

                if (!ret)
                {
                    Console.WriteLine("Unable to add the tool!");
                }
            }

            toolbox.Display();

            for (int i = 0; i < NUM_TOOLS; i++)
            {
                tool[i] = null;
            }

            Console.ReadLine();
        }
    }
}

