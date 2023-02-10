using System;

namespace TemplatePatternApp 
{
    /* 足球比赛 */
    public class FootballGame : Game
    {
        // 只需要重写虚函数即可
        protected override bool Initialize()
        {
            Console.WriteLine("Build football ground...");
            Console.WriteLine("Wait players...");
            return true;
        }
        protected override int PlayGame()
        {
            Console.WriteLine("Playing...");
            Console.WriteLine("titititi");
            return 4;
        }
        protected override void EndPlay()
        {
            Console.WriteLine("Recover ground");
            Console.WriteLine("Clean place");
        }
    }
}