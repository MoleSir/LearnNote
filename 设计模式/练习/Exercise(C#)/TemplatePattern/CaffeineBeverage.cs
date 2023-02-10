/* 咖啡因饮料基类 */
using System;

namespace TemplatePatternApplication
{
    public abstract class CaffeineBeverage 
    {
        // 制作饮料
        public void PrepareRecipe()
        {
            // 先烧水
            this.BoilWater();

            // 泡制
            this.Brew();

            // 倒水
            this.PourInCup();

            // 加料
            this.AddCondiments();
        }

        // 两个需要子类实现的函数
        // 泡制
        protected abstract void Brew(); 

        // 添加咖啡因
        protected abstract void AddCondiments();
    
        // 两个不需要重写的函数
        // 烧开水，对什么饮料都是一样的步骤
        void BoilWater() 
        {
            Console.WriteLine("BoilWater");
        }   

        // 倒水到杯子
        void PourInCup() 
        {
            Console.WriteLine("PourInCup");
        }
    }
}