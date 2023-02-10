/* 保存过去的所有计算器备忘录的 CareTaker 类 */
using System.Collections.Generic;
using System;

namespace MementoPatternApplication
{
    public class PreviousCalculationToCareTaker
    {
        // 构造函数
        public PreviousCalculationToCareTaker()
        {
            this.mementos = new Dictionary<string, PreviousCalculationToOriginator>();
        }

        // 添加新的备忘录，并且打上标签用来查找
        public void AddMemento(string tag, PreviousCalculationToOriginator memento)
        {
            // 检查标签是否存在
            if (this.mementos.ContainsKey(tag) == true)
            {
                Console.WriteLine("{tag} tag already exits, please use other tag.");
                return;
            }

            // 加入备忘录
            this.mementos.Add(tag, memento);
        }

        // 取出指定下标的备忘录对象
        public PreviousCalculationToOriginator GetMemento(string tag)
        {
            // 检查标签是否存在
            if (this.mementos.ContainsKey(tag) == false)
            {
                Console.WriteLine("no {tag} tag exits.");
                return null;
            }
            return this.mementos[tag];
        }

        // 保存过去各个备忘录
        private Dictionary<string, PreviousCalculationToOriginator> mementos;
    }
}