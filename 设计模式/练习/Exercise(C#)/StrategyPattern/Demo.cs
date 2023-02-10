/*
* 设计一个鸭子，它可以动态地改变叫声。这里的算法族是鸭子的叫声行为。
*/
namespace StrategyPatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            Duck duck = new Duck();

            duck.SetShoutObject(new Quack());
            duck.PerformShoutOut();

            duck.SetShoutObject(new Squeak());
            duck.PerformShoutOut();
        }
    }
}