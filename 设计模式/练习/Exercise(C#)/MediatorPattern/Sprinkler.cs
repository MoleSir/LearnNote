/* 同事实现 */
using System;

namespace MediatorPatternApplication
{
    public class Sprinkler : Colleague
    {
        // 实现接口
        public void DoEvent(Mediator mediator)
        {
            mediator.DoEvent("sprinkler");
        }

        // 闹钟函数
        public void DoSprinkler()
        {
            Console.WriteLine("DoSprinkler()");
        }
    }
}