namespace MediatorPatternApplication
{
    class Program
    {
        static void Main()
        {
            Alarm alarm = new Alarm();
            CoffeePot coffeePot = new CoffeePot();
            Calender calender = new Calender();
            Sprinkler sprinkler = new Sprinkler();
            Mediator mediator = new ConcreteMediator(alarm, calender, coffeePot, sprinkler);
            // 闹钟事件到达，调用中介者就可以操作相关对象
            alarm.DoEvent(mediator);
        }
    }
}