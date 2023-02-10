/*
* 设计一个遥控器，可以控制电灯开关
*/
namespace CommandPatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            Invoker invoker = new Invoker(5);
            Light light = new Light();

            Command lightOnCommand = new LightOnCommand(light);
            Command lightOffCommand = new LightOffCommand(light);

            invoker.SetOnCommand(0, lightOnCommand);
            invoker.SetOffCommand(0, lightOffCommand);
            invoker.OnButtonWasPushed(0);
            invoker.OffButtonWasPushed(0);
        }
    }
}