/* 电视子类实现，Sony */
using System;

namespace BridgePatternApplication
{
    public class Sony : TV
    {
        // 开电视
        public void On()
        {
            Console.WriteLine("Sony.On()");
        }

        // 关电视
        public void Off()
        {
            Console.WriteLine("Sony.Off()");
        }

        // 切换频道
        public void TuneChannel()
        {
            Console.WriteLine("Sony.Tune Channel");
        }
    }
}