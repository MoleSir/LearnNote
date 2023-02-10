/* 同事实现类，闹钟类 */
using System;

namespace MediatorPatternApplication
{
    public class Alarm : Colleague
    {
        // 实现接口
        public void DoEvent(Mediator mediator)
        {
            mediator.DoEvent("alarm");
        }

        // 闹钟函数
        public void DoAlarm()
        {
            Console.WriteLine("DoAlarm()");
        }
    }
}