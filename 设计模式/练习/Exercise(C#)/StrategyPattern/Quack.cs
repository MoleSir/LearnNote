/* 嘎嘎叫的实现 */
using System;

namespace StrategyPatternApplication
{
    public class Quack : ShoutBehavior
    {
        public void ShoutOut()
        {
            Console.WriteLine("quack~~");
        }
    }
}