/* 状态实现类，出售状态 */
using System;

namespace StatePatternApplication
{
    public class SoldState : State
    {       
        // 构造函数
        public SoldState(GumballMachine gumballMachine) : base(gumballMachine) {}

        // 投入 25 分钱
        public override void InsertQuarter()
        {   
            // 已经付过钱了，现在正在出货
            Console.WriteLine("Please wait, we're already giving you a gumball");
        }

        // 退回 25 分钱
        public override void EjectQuarter()
        {
            // 钱已经付过了，怎么退
            Console.WriteLine("Sorry, you already turned the crank");
        }

        // 转动曲柄
        public override void TurnCrank()
        {
            // 转了，别再转到了好吗
            Console.WriteLine("Turning twice doesn't get you another gumball!");
        }

        // 发放糖果
        public override void Dispense()
        {   
            // 放出一个糖果
            this.gumballMachine.ReleaseBall();

            // 根据剩下的糖果数量，设置贩卖机状态
            if (this.gumballMachine.GetCount() > 0) 
            {
                this.gumballMachine.SetState(gumballMachine.GetNoQuarterState());
            } 
            else 
            {
                Console.WriteLine("Oops, out of gumballs");
                gumballMachine.SetState(gumballMachine.GetSoldOutState());
            }
        }
    }
}