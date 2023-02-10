/* 同事实现类，咖啡类 */
using System;

namespace MediatorPatternApplication
{
    public class CoffeePot : Colleague
    {
        // 实现接口
        public void DoEvent(Mediator mediator)
        {
            mediator.DoEvent("coffeePot");
        }

        // 闹钟函数
        public void DoCoffeePot()
        {
            Console.WriteLine("DoCoffeePot()");
        }
    }
}