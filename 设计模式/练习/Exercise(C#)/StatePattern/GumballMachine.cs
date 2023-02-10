/* 贩卖机 */
using System;

namespace StatePatternApplication
{
    public class GumballMachine
    {
        // 构造函数，设置糖果数量
        public GumballMachine(int numberGumballs)
        {
            // 创建四种状态
            this.soldOutState = new SoldOutState(this);
            this.noQuarterState = new NoQuarterState(this);
            this.hasQuarterState = new HasQuarterState(this);
            this.soldState = new SoldState(this);

            this.count = numberGumballs;
            // 根据数量置初始状态
            if (this.count > 0)
                this.state = this.noQuarterState;            
            else 
                this.state = this.soldOutState;
        }
        
        // 给贩卖机存钱
        public void InsertQuarter() 
        {
            this.state.InsertQuarter();
        }

        // 让贩卖机退钱
        public void EjectQuarter() 
        {
            this.state.EjectQuarter();
        }

        // 扳手柄
        public void TurnCrank() {
            this.state.TurnCrank();
            this.state.Dispense();
        }

        // 设置状态
        public void SetState(State state) {
            this.state = state;
        }

        // 出一个糖
        public void ReleaseBall() 
        {
            Console.WriteLine("A gumball comes rolling out the slot...");
            if (this.count != 0) 
            {
                count -= 1;
            }
        }

        public State GetSoldOutState() 
        {
            return this.soldOutState;
        }

        public State GetNoQuarterState() 
        {
            return this.noQuarterState;
        }

        public State GetHasQuarterState() 
        {
            return this.hasQuarterState;
        }

        public State GetSoldState() 
        {
            return this.soldState;
        }

        public int GetCount() 
        {
            return this.count;
        }

        // 四种状态
        private State soldOutState;
        private State noQuarterState;
        private State hasQuarterState;
        private State soldState;

        // 当前状态
        private State state;
        private int count;
    }
}