/* 中介者接口 */
namespace MediatorPatternApplication
{
    public interface Mediator
    {
        void DoEvent(string eventType);
    }
}