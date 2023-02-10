/* 观察者子类实现：根据当前条件显示 */
using System;

namespace ObserverPatternApplication
{
    public class CurrentConditionsDisplay : Observer
    {
        // 构造函数
        public CurrentConditionsDisplay(Subject weatherData)
        {
            // 将观察者加入
            weatherData.RegisterObserver(this);
        }

        // 打印数据
        public void Update(float temperature, float humidity, float pressure)
        {
            Console.WriteLine("Current Conditions Display:");
            Console.WriteLine("Temperature: {0}, Humidity: {1}, Pressure: {2}", 
                              temperature, humidity, pressure);
        }
    }
}