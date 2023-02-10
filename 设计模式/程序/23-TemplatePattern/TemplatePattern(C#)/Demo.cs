using System;

namespace TemplatePatternApp 
{
    class Program
    {
        static void Main()
        {
            Game footballGame = new FootballGame();
            Console.WriteLine("Welcome to Football Game!");
            footballGame.Play();

            Console.WriteLine("");

            Game cricketGame = new CricketGame();
            Console.WriteLine("Welcome to Cricket Game!");
            cricketGame.Play();   
        }
    }
}