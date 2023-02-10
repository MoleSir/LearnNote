/* 一个比较复杂的系统，看电源需要很多步骤 */
using System;

namespace FacadePatternApplication
{
    public class SubSystem
    {
        // 开启电视
        public void TurnOnTV() 
        {
            Console.WriteLine("TurnOnTV()");
        }

        // 放置 CD
        public void SetCD(string CD) 
        {
            Console.WriteLine("SetCD({0})", CD);
        }

        // 开始观看
        public void StartWatching(){
            Console.WriteLine("StartWatching()");
        }
    }
}