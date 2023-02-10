/* C++ 实现创造者模式 */
#include <iostream>
#include <string>
#include <list>


namespace BuilderPattern
{
    /* 创建一个表示食物条目和食物包装的接口 *******************************************/
    class Packing
    {
    public:
        virtual std::string pack() = 0;
    };

    class Item
    {
    public:
        virtual std::string name() = 0;
        virtual Packing* packing() = 0;
        virtual float price() = 0;
    };


    /* 创建实现 Packing 接口的实体类 ************************************************/
    class Wrapper: public Packing
    {
    public:
        virtual std::string pack() override
        {
            // 袋装包装
            return std::string("Wrapper");
        }
    };

    class Bottle: public Packing
    {
    public:
        virtual std::string pack() override
        {   
            // 瓶装包装
            return std::string("Bottle");
        }
    };

    
    /* 创建实现 Item 接口的抽象类，该类提供了默认的功能 *********************************/
    // 汉堡类的实现，这也是一个抽象类
    class Burger: public Item
    {
    public:
        // 抽象汉堡类只能给出汉堡是袋装的
        virtual Packing* packing() override
        {
            return new Wrapper();
        }
    };

    // 饮料类的实现，这也是一个抽象类
    class Drink: public Item
    {
    public:
        // 饮料抽象类只能给出饮料是瓶装的
        virtual Packing* packing() override
        {
            return new Bottle();
        }
    };


    /* 创建扩展了 Burger 和 Drink 的实体类 **********************************************/
    // 蔬菜汉堡类，这是一个真实的类，不再抽象
    class VegBurger: public Burger
    {
    public:
        // 可以给出名称
        virtual std::string name() override
        {
            return std::string("Veg Burger");
        }
        // 可以给出价格
        virtual float price() override
        {
            return 8.0;
        }
    };

    // 鸡肉汉堡类，这是一个真实的类，不再抽象
    class ChickenBurger: public Burger
    {
    public:
        // 可以给出名称
        virtual std::string name() override
        {
            return std::string("Chicken Burger");
        }
        // 可以给出价格
        virtual float price() override
        {
            return 14.5;
        }
    };

    // 可口可乐类，这是一个真实的类，不再抽象
    class Coke: public Drink
    {
    public:
        // 可以给出名称
        virtual std::string name() override
        {
            return std::string("Coke");
        }
        // 可以给出价格
        virtual float price() override
        {
            return 4.0;
        }
    };

    // 百事可乐类，这是一个真实的类，不再抽象
    class Pepsi: public Drink
    {
    public:
        // 可以给出名称
        virtual std::string name() override
        {
            return std::string("Pepsi");
        }
        // 可以给出价格
        virtual float price() override
        {
            return 4.5;
        }
    };

    
    /* 创建一个 Meal 类，带有上面定义的 Item 对象 ************************************/
    class Meal
    {
    public:
        Meal(): items() 
        {}
        // 析构函数负责释放链表中的堆区变量
        ~Meal()
        {
            for (Item* item : this->items)
                delete item;
        }
        // 添加物品函数
        void AddItem(Item* item) 
        {
            this->items.push_back(item);
        }
        // 显示物品
        void ShowItems() const
        {
            std::cout << "Show this Meal's Items' infomations:" << std::endl;
            for (Item* item : this->items)
            {
                std::cout << "Item Name: " << item->name() << ",   ";
                Packing* tempPack = item->packing();
                std::cout << "Item Pack: " << tempPack->pack() << ",   ";
                std::cout << "Item Price: " << item->price() << std::endl;
                delete tempPack;
            }
        }
    private:
        // 链表保持点餐的物品
        std::list<Item*> items;
    };


    /* 创建一个 MealBuilder 类，实际的 builder 类负责创建 Meal 对象 *********************/
    class MealBuilder
    {
    public:
        // 素食套餐
        Meal* PrepareVegMeal()
        {
            Meal* meal = new Meal();
            meal->AddItem(new VegBurger());
            meal->AddItem(new Coke());
            return meal;
        }
        // 非素食套餐
        Meal* PrepareNonVegMeal()
        {
            Meal* meal = new Meal();
            meal->AddItem(new ChickenBurger());
            meal->AddItem(new Pepsi());
            return meal;
        }
        // 还可以继续添加套餐......
    };
}


int main()
{
    using namespace BuilderPattern;

    // 实例化一个食品创建者
    MealBuilder mealBuilder;
    
    // 来份素食套餐
    Meal* vegMeal = mealBuilder.PrepareVegMeal();
    // 来份非素食套餐
    Meal* nonVegMeal = mealBuilder.PrepareNonVegMeal();

    // 康康
    vegMeal->ShowItems();
    nonVegMeal->ShowItems();

    delete vegMeal;
    delete nonVegMeal;
    return 0;
}