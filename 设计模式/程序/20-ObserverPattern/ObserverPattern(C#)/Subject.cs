using System;
using System.Collections.Generic;

namespace ObserverPatternApp
{
    /* 创建 Subject 类 */
    public class Subject
    {
        public Subject(int state)
        {
            this.state = state;
            this.observers = new List<Observer>();
        }
        // 添加观察者
        public void AddObserver(Observer observer)
        {
            this.observers.Add(observer);
        }
        // 改变状态
        public void SetState(int newState)
        {
            this.state = newState;
            // 发送通知给观察者
            this.NotifyAllObservers();
        }
        // 通知所有观察者
        private void NotifyAllObservers()
        {
            foreach (Observer observer in this.observers)
                observer.Uptate(this.state);
        }

        // 类的状态
        private int state;
        // 观察者链表
        private List<Observer> observers;
    }
}