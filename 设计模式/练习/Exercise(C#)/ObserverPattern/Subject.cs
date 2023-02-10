/* 待观察对象接口 */
namespace ObserverPatternApplication
{
    public interface Subject
    {
        // 注册观察者
        void RegisterObserver(Observer observer);

        // 移除观察者
        void RemoveObserver(Observer observer);

        // 唤醒观察者
        void NotifyObservers();
    }
}