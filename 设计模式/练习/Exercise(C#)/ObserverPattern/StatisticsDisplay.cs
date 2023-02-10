/* 观察者子类实现：显示天气数据 */
using System;

namespace ObserverPatternApplication
{
    public class StatisticsDisplay : Observer
    {
        // 构造函数
        public StatisticsDisplay(Subject weatherData)
        {
            // 将观察者加入
            weatherData.RegisterObserver(this);
        }

        // 打印数据
        public void Update(float temperature, float humidity, float pressure)
        {
            Console.WriteLine("Statistics Display:");
            Console.WriteLine("Temperature: {0}, Humidity: {1}, Pressure: {2}", 
                              temperature, humidity, pressure);
        }
    }
}