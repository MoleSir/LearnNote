/* 咖啡因饮料子类实现，咖啡 */
using System;

namespace TemplatePatternApplication
{
    public class Coffee : CaffeineBeverage
    {
        // 实现泡制
        protected override void Brew()
        {
            Console.WriteLine("Coffee.Brew");
        }

        // 实现添加咖啡因
        protected override void AddCondiments()
        {
            Console.WriteLine("Coffee.Add Condiments");
        }
    }
}