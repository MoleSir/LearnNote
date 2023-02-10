/* 状态实现类，售卖机的钱大于 25 美分 */
using System;

namespace StatePatternApplication
{
    public class HasQuarterState : State
    {       
        // 构造函数
        public HasQuarterState(GumballMachine gumballMachine) : base(gumballMachine) {}

        // 投入 25 分钱
        public override void InsertQuarter()
        {
            // 已经有了 25 块钱，不能再放了
            Console.WriteLine("You can't insert another quarter");
        }

        // 退回 25 分钱
        public override void EjectQuarter()
        {
            Console.WriteLine("Quarter returned");
            // 改变状态为没有钱状态
            this.gumballMachine.SetState(gumballMachine.GetNoQuarterState());
        }

        // 转动曲柄
        public override void TurnCrank()
        {
            Console.WriteLine("You turned...");
            // 改变状态为出售状态
            this.gumballMachine.SetState(gumballMachine.GetSoldState());
        }

        // 发放糖果
        public override void Dispense()
        {
            // 现在的状态只是存了钱，还不能发糖
            Console.WriteLine("No gumball dispensed");
        }
    }
}