/* 状态实现类，售卖机没有糖果了 */
using System;

namespace StatePatternApplication
{
    public class SoldOutState : State
    {       
        // 构造函数
        public SoldOutState(GumballMachine gumballMachine) : base(gumballMachine) {}

        // 投入 25 分钱
        public override void InsertQuarter()
        {
            // 没有糖果了，不能存
            Console.WriteLine("You can't insert a quarter, the machine is sold out");
        }

        // 退回 25 分钱
        public override void EjectQuarter()
        {
            // 没有钱，不能退钱
            Console.WriteLine("You can't eject, you haven't inserted a quarter yet");
        }

        // 转动曲柄
        public override void TurnCrank()
        {
            // 转了，但是糖
            Console.WriteLine("You turned, but there are no gumballs");
        }

        // 发放糖果
        public override void Dispense()
        {
            // 没有糖了
            Console.WriteLine("No gumball dispensed");
        }
    }
}