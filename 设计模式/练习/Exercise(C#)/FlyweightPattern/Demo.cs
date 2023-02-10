namespace FlyweightPatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            FlyweightFactory factory = new FlyweightFactory();
            Flyweight flyweight1 = factory.GetFlyweight("aa");
            Flyweight flyweight2 = factory.GetFlyweight("aa");
            flyweight1.DoOperation("x");
            flyweight1.DoOperation("y");
        }
    }
}