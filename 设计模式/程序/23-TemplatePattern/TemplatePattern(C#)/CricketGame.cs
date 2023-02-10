using System;

namespace TemplatePatternApp 
{
    /* Cricket 比赛 */
    public class CricketGame : Game
    {
        // 只需要重写虚函数即可
        protected override bool Initialize()
        {
            Console.WriteLine("Build cricketGame ground...");
            Console.WriteLine("Wait players...");
            return true;
        }
        protected override int PlayGame()
        {
            Console.WriteLine("Playing...");
            Console.WriteLine("hithithit");
            return 10;
        }
        protected override void EndPlay()
        {
            Console.WriteLine("Recover ground");
            Console.WriteLine("Clean place");
            Console.WriteLine("Free Source");
        }
    }
}