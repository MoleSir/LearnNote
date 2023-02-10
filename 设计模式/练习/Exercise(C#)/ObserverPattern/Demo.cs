/*
* 天气数据布告板会在天气信息发生改变时更新其内容，
* 布告板有多个，并且在将来会继续增加
*/
namespace ObserverPatternApplication
{
    class Program
    {
        static void Main(string[] agrs)
        {
            WeatherData weatherData = new WeatherData();
            CurrentConditionsDisplay currentConditionsDisplay = new CurrentConditionsDisplay(weatherData);
            StatisticsDisplay statisticsDisplay = new StatisticsDisplay(weatherData);

            weatherData.SetMeasurements(0, 0, 0);
            weatherData.SetMeasurements(1, 1, 1);
        }
    }
}