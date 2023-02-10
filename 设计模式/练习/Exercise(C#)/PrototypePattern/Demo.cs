using System;

namespace PrototypePatternApplication
{
    class Program
    {
        static void Main()
        {
            Prototype p1 = new ConcretePrototype("yechen", 95, 1.0);
            Prototype p2 = p1.Clone();
            Console.WriteLine("p1: {0}", p1.ToString());
            Console.WriteLine("p2: {0}", p2.ToString());
        }
    }
}