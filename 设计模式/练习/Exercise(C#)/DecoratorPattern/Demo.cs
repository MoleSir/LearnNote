/*
* 设计不同种类的饮料，饮料可以添加配料。
* 比如可以添加牛奶，并且支持动态添加新配料。
* 每增加一种配料，该饮料的价格就会增加，要求计算一种饮料的价格。
*/
using System;

namespace DecoratorPatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            // 焦糖咖啡
            DarkRoast darkRoast = new DarkRoast();
            // 星巴克首席咖啡
            HouseBlend houseBlend = new HouseBlend();

            // 焦糖 + 牛奶
            Mike mike1 = new Mike(darkRoast);
            Console.WriteLine("DarkRoast + Mike cost: {0}", mike1.Cost());

            // 星巴克 + 牛奶
            Mike mike2 = new Mike(houseBlend);
            Console.WriteLine("HouseBlend + Mike cost: {0}", mike2.Cost());

            // 摩卡 + 焦糖
            Mocha macha1 = new Mocha(darkRoast);
            Console.WriteLine("DarkRoast + Mocha cost: {0}", macha1.Cost());

            // 摩卡 + 星巴克
            Mocha macha2 = new Mocha(houseBlend);
            Console.WriteLine("HouseBlend + Mocha cost: {0}", macha2.Cost());
        }
    }
}