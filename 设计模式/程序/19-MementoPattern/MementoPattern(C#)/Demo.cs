/* C# 备忘录模式 */
using System;
using System.Collections.Generic;

namespace MementoPatternApp
{
    /* 创建 Memento(纪念品) 类，用来保存状态*/ 
    class Memento
    {
        public Memento(string state)
        {
            this.state = state;
        }
        public string State
        {
            get
            {
                return this.state;
            }
            set
            {
                this.state = value;
            }
        }
        private string state;
    }
    

    /* 创建 Originator 类，完美需要版本控制的类 */
    class Originator
    {
        public string State
        {
            get
            {
                return this.state;
            }
            set
            {   
                this.state = value;
            }
        }
        // 获取当前状态，保存到一个备忘录中
        public Memento SaveStateToMemento()
        {
            return new Memento(this.state);
        }
        // 从某个备忘录中恢复状态
        public void GetStateFromMemento(Memento memento)
        {
            this.state = memento.State;
        }
        private string state;
    }

    /* 创建 CareTaker 类，保存往期状态的类 */
    class CareTaker
    {
        public CareTaker()
        {
            this.mementos = new List<Memento>();
        }
        // 添加备忘录
        public void Add(Memento memento)
        {
            this.mementos.Add(memento);
        }
        // 获取第几个版本的备忘录
        public Memento Get(int index)
        {
            return this.mementos[index];
        }
        // 保存备忘录链表
        private List<Memento> mementos;
    }

    class Program
    {
        static void Main(string[] args)
        {
            Originator originator = new Originator();
            CareTaker careTaker = new CareTaker();
            originator.State = "State #1";
            originator.State = "State #2";
            careTaker.Add(originator.SaveStateToMemento());
            originator.State = "State #3";
            careTaker.Add(originator.SaveStateToMemento());
            originator.State = "State #4";

            Console.WriteLine("Current State: " + originator.State);    
            originator.GetStateFromMemento(careTaker.Get(0));
            Console.WriteLine("First saved State: " + originator.State);
            originator.GetStateFromMemento(careTaker.Get(1));
            Console.WriteLine("Second saved State: " + originator.State);
        }
    }
}