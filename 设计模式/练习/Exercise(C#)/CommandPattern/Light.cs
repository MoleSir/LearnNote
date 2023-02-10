/* 灯类 */
using System;

namespace CommandPatternApplication
{
    public class Light
    {
        // 开灯
        public void On()
        {
            Console.WriteLine("Light is On!");
        }

        // 关灯
        public void Off()
        {
            Console.WriteLine("Light is Off!");
        }
    }
}