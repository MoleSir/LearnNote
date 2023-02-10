/* 状态抽象类 */
namespace StatePatternApplication
{
    public abstract class State
    {   
        // 构造函数
        public State(GumballMachine gumballMachine)
        {
            this.gumballMachine = gumballMachine;
        }

        // 不同的状态有不同的以下四种函数实现
        // 投入 25 分钱
        public abstract void InsertQuarter();

        // 退回 25 分钱
        public abstract void EjectQuarter();

        // 转动曲柄
        public abstract void TurnCrank();

        // 发放糖果
        public abstract void Dispense();

        // 贩卖机
        protected GumballMachine gumballMachine;
    }
}