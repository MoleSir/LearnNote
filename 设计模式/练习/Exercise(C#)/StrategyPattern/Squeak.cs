/* squeak 叫的实现 */
using System;

namespace StrategyPatternApplication
{
    public class Squeak : ShoutBehavior
    {
        public void ShoutOut()
        {
            Console.WriteLine("squeak~~");
        }
    }
}