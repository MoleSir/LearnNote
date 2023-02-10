/*
* TV 表示电视，指代 Implementor。
* 桥接模式将遥控器和电视分离开来，从而可以独立改变遥控器或者电视的实现。
*/
using System;

namespace BridgePatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            RemoteControl remoteControl1 = new ConcreteRemoteControl1(new RCA());
            remoteControl1.On();
            remoteControl1.Off();
            remoteControl1.TuneChannel();

            RemoteControl remoteControl2 = new ConcreteRemoteControl2(new Sony());
            remoteControl2.On();
            remoteControl2.Off();
            remoteControl2.TuneChannel();
        }
    }
}