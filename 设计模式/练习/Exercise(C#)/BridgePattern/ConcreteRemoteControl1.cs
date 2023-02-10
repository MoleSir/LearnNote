/* 遥控器子类实现1 */
using System;

namespace BridgePatternApplication
{
    public class ConcreteRemoteControl1 : RemoteControl
    {
        // 构造函数
        public ConcreteRemoteControl1(TV tv) : base(tv) {}

        // 开电视
        public override void On()
        {
            Console.WriteLine("ConcreteRemoteControl1.On()");
            this.tv.On();
        }

        // 关电视
        public override void Off()
        {
            Console.WriteLine("ConcreteRemoteControl1.Off()");
            this.tv.Off();
        }

        // 切换频道
        public override void TuneChannel()
        {
            Console.WriteLine("ConcreteRemoteControl1.TuneChannel()");
            this.tv.TuneChannel();
        }
    }
}