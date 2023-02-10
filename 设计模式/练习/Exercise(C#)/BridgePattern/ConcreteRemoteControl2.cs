/* 遥控器子类实现2 */
using System;

namespace BridgePatternApplication
{
    public class ConcreteRemoteControl2 : RemoteControl
    {
        // 构造函数
        public ConcreteRemoteControl2(TV tv) : base(tv) {}

        // 开电视
        public override void On()
        {
            Console.WriteLine("ConcreteRemoteControl2.On()");
            this.tv.On();
        }

        // 关电视
        public override void Off()
        {
            Console.WriteLine("ConcreteRemoteControl2.Off()");
            this.tv.Off();
        }

        // 切换频道
        public override void TuneChannel()
        {
            Console.WriteLine("ConcreteRemoteControl2.TuneChannel()");
            this.tv.TuneChannel();
        }
    }
}