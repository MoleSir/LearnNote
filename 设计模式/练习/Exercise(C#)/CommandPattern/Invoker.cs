/* 遥控器类 */
using System;

namespace CommandPatternApplication
{
    public class Invoker
    {
        // 构造函数
        public Invoker(int slotNum)
        {
            this.slotNum = slotNum;
            this.onCommands = new Command[slotNum];
            this.offCommands = new Command[slotNum];
        }

        // 设置开灯命令
        public void SetOnCommand(int index, Command command)
        {
            if (this.CheckIndex(index) == true)
                this.onCommands[index] = command;
        }

        // 设置关灯命令
        public void SetOffCommand(int index, Command command)
        {
            if (this.CheckIndex(index) == true) 
                this.offCommands[index] = command;
        }

        // 执行开灯命令
        public void OnButtonWasPushed(int index)
        {
            if (this.CheckIndex(index) == true)
                this.onCommands[index].Execute();
        }

        // 执行关灯命令
        public void OffButtonWasPushed(int index)
        {
            if (this.CheckIndex(index) == true)
                this.offCommands[index].Execute();
        }

        // 检测数组下标
        private bool CheckIndex(int index)
        {
            if (index > this.slotNum)
            {
                Console.WriteLine("index of out range");
                return false;
            }
            return true;
        }

        // 命令数组
        private Command[] onCommands;
        private Command[] offCommands;
        // 命令个数
        private int slotNum;
    }
}