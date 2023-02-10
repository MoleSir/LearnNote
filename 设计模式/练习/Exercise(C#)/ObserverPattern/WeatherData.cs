/* 待观察对象子类实现：天气报告 */
using System.Collections.Generic;

namespace ObserverPatternApplication
{
    public class WeatherData : Subject
    {
        // 构造函数
        public WeatherData()
        {
            this.observers = new List<Observer>();
        }

        // 设置天气数据
        public void SetMeasurements(float temperature, float humidity, float pressure)
        {
            this.temperature = temperature;
            this.humidity = humidity;
            this.pressure = pressure;
            // 唤醒所有观察者
            this.NotifyObservers();
        }

        // 注册观察者
        public void RegisterObserver(Observer observer)
        {
            this.observers.Add(observer);
        }

        // 移除观察者
        public void RemoveObserver(Observer observer)
        {
            this.observers.Remove(observer);
        }

        // 唤醒观察者
        public void NotifyObservers()
        {
            foreach (Observer observer in this.observers)
                observer.Update(this.temperature, this.humidity, this.pressure);
        }

        // 天气数据，温度、湿度、气压
        private float temperature;
        private float humidity;
        private float pressure;
        // 观察者列表
        private List<Observer> observers;
    }
}