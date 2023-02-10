/* 火鸡接口实现，野火鸡 */
using System;

namespace AdapterPatternApplication
{
    public class WildTurkey : Turkey
    {
        public void Gobble()
        {
            Console.WriteLine("Gobble!!");
        }
    }
}