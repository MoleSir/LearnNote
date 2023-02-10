/* 同事实现类，日历类 */
using System;

namespace MediatorPatternApplication
{
    public class Calender : Colleague
    {
        // 实现接口
        public void DoEvent(Mediator mediator)
        {
            mediator.DoEvent("calender");
        }

        // 闹钟函数
        public void DoCalender()
        {
            Console.WriteLine("DoCalender()");
        }
    }
}