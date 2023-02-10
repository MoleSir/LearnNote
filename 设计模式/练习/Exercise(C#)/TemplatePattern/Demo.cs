/*
* 冲咖啡和冲茶都有类似的流程，
* 但是某些步骤会有点不一样，要求复用那些相同步骤的代码。
*/
using System;

namespace TemplatePatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            CaffeineBeverage caffeineBeverage = new Coffee();
            caffeineBeverage.PrepareRecipe();
            Console.WriteLine("-----------");

            caffeineBeverage = new Tea();
            caffeineBeverage.PrepareRecipe();
        }
    }
}