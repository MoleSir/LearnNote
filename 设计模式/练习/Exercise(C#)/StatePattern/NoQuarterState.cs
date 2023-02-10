/* 状态实现类，售卖机没有钱存入 */
using System;

namespace StatePatternApplication
{
    public class NoQuarterState : State
    {       
        // 构造函数
        public NoQuarterState(GumballMachine gumballMachine) : base(gumballMachine) {}

        // 投入 25 分钱
        public override void InsertQuarter()
        {
            Console.WriteLine("You insert a quarter");
            // 改变状态为存入 25 
            this.gumballMachine.SetState(gumballMachine.GetHasQuarterState());
        }

        // 退回 25 分钱
        public override void EjectQuarter()
        {
            // 没有钱，不能退钱
            Console.WriteLine("You haven't insert a quarter");
        }

        // 转动曲柄
        public override void TurnCrank()
        {
            // 转了，但是没有钱
            Console.WriteLine("You turned, but there's no quarter");
        }

        // 发放糖果
        public override void Dispense()
        {
            // 要发糖果，先给钱
            Console.WriteLine("You need to pay first");
        }
    }
}