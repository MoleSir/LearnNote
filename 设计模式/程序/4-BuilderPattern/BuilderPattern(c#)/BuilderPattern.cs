/* 使用C#实现建造者模式 */
using System;
using System.Collections.Generic;


namespace BuilderPattern
{
    /* 创建一个表示食物条目和食物包装的接口 *******************************************/
    public interface Packing
    {
        string pack();
    }

    public interface Item
    {
        string name();
        Packing packing();
        double  price();
    }


    /* 创建实现 Packing 接口的实体类 ************************************************/
    public class Wrapper: Packing
    {
        public string pack()
        {
            return "Wrapper";
        }
    }

    public class Buttle: Packing
    {
        public string pack()
        {
            return "Buttle";
        }
    }


    /* 创建实现 Item 接口的抽象类，该类提供了默认的功能 *********************************/
    // 抽象类：汉堡类，我们只能确定其包装是 Wrapper
    public abstract class Burger: Item
    {
        public Packing packing()
        {
            return new Wrapper();
        }
        public abstract string name();
        public abstract double price();
    }

    // 抽象类：饮料类，我们只能确定其包装是 Buttle
    public abstract class Drink: Item
    {
        public Packing packing()
        {
            return new Buttle();
        }
        public abstract string name();
        public abstract double price();
    }


    /* 创建扩展了 Burger 和 Drink 的实体类 **********************************************/
    // 具体类：蔬菜汉堡
    public class VegBurger: Burger
    {
        public override string name()
        {
            return "Veg Burger";
        }
        public override double price()
        {
            return 8.0;
        }
    }

    // 具体类：鸡肉汉堡
    public class ChickenBurger: Burger
    {
        public override string name()
        {
            return "Chicken Burger";
        }
        public override double price()
        {
            return 12.5;
        }
    }

    // 可口可乐类
    public class Coke: Drink
    {
        public override string name()
        {
            return "Coke";
        }
        public override double price()
        {
            return 3.5;
        }   
    }

    // 百事可乐类
    public class Pepsi: Drink
    {
        public override string name()
        {
            return "Pepsi";
        }
        public override double price()
        {
            return 4.0;
        }
    }


    /* 创建一个 Meal 类，带有上面定义的 Item 对象 ************************************/
    public class Meal
    {
        public Meal()
        {
            items = new List<Item>();
        }
        public void AddItem(Item item)
        {
            this.items.Add(item);
        }
        public void ShowItems()
        {
            foreach (Item item in this.items)
            {
                Console.WriteLine("Show this Meal's Items' infomations:");
                Console.WriteLine("Item Name: " + item.name() + ",   " + 
                                  "Item Pack: " + item.packing().pack() + ",   " + 
                                  "Item Price: {0}", item.price());
            }
        }

        private List<Item> items;
    }


    /* 创建一个 MealBuilder 类，实际的 builder 类负责创建 Meal 对象 *********************/
    public class MealBuilder
    {
        // 素食套餐
        public Meal PrepareVegMeal()
        {
            Meal meal = new Meal();
            meal.AddItem(new VegBurger());
            meal.AddItem(new Coke());
            return meal;
        }
        // 非素食套餐
        public Meal PrepareNonVegMeal()
        {
            Meal meal = new Meal();
            meal.AddItem(new ChickenBurger());
            meal.AddItem(new Pepsi());
            return meal;
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            MealBuilder mealBuilder = new MealBuilder();

            Meal vegMeal = mealBuilder.PrepareVegMeal();
            Meal nonvegMeal = mealBuilder.PrepareNonVegMeal();

            vegMeal.ShowItems();
            nonvegMeal.ShowItems();
        }
    }
}