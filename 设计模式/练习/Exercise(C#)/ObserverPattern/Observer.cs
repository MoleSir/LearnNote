/* 观察者接口 */
namespace ObserverPatternApplication
{
    public interface Observer
    {
        // 更新信息，观察者对天气信息作出反应
        void Update(float temperature, float humidity, float pressure);
    }
}