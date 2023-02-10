/* 电视子类实现，RAC */
using System;

namespace BridgePatternApplication
{
    public class RCA : TV
    {
        // 开电视
        public void On()
        {
            Console.WriteLine("RCA.On()");
        }

        // 关电视
        public void Off()
        {
            Console.WriteLine("RCA.Off()");
        }

        // 切换频道
        public void TuneChannel()
        {
            Console.WriteLine("RCA.Tune Channel");
        }
    }
}