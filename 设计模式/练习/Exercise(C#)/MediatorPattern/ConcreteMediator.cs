/* 中介者的具体实现 */
namespace MediatorPatternApplication
{
    public class ConcreteMediator : Mediator
    {
        // 构造函数
        public ConcreteMediator(Alarm alarm, Calender calender, CoffeePot coffeePot, Sprinkler sprinkler)
        {
            this.alarm = alarm;
            this.calender = calender;
            this.coffeePot = coffeePot;
            this.sprinkler = sprinkler;
        }

        // 实现接口
        public void DoEvent(string eventType)
        {
            switch (eventType)
            {
            case "alarm":
                this.DoAlarmEvent();
                break;
            case "calender":
                this.DoCalenderEvent();
                break;
            case "coffeePot":
                this.DoCoffeePotEvent();
                break;
            case "sprinkler":
                this.DoSprinklerEvent();
                break;
            }
        }

        public void DoAlarmEvent() 
        {
            alarm.DoAlarm();
            coffeePot.DoCoffeePot();
            calender.DoCalender();
            sprinkler.DoSprinkler();
        }

        public void DoCoffeePotEvent() 
        {
            // ...
        }

        public void DoCalenderEvent() 
        {
            // ...
        }

        public void DoSprinklerEvent() 
        {
            // ...
        }

        // 四个同事
        private Alarm alarm;
        private Calender calender;
        private CoffeePot coffeePot;
        private Sprinkler sprinkler;
    }
}