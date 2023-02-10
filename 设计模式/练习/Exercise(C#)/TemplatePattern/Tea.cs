/* 咖啡因饮料子类实现，茶 */
using System;

namespace TemplatePatternApplication
{
    public class Tea : CaffeineBeverage
    {
        // 实现泡制
        protected override void Brew()
        {
            Console.WriteLine("Tea.Brew");
        }

        // 实现添加咖啡因
        protected override void AddCondiments()
        {
            Console.WriteLine("Tea.Add Condiments");
        }
    }
}