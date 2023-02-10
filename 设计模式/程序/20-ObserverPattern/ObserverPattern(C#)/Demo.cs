using System;

namespace ObserverPatternApp
{
    class Program
    {
        static void Main()
        {
            Subject subject = new Subject(0);

            HexaObserver h =  new HexaObserver();
            OctalObserver o =  new OctalObserver();
            BinaryObserver b =  new BinaryObserver();

            subject.AddObserver(h);
            subject.AddObserver(o);
            subject.AddObserver(b);

            Console.WriteLine("First state change: 15");   
            subject.SetState(15);
            Console.WriteLine("Second state change: 10");  
            subject.SetState(10);
        }
    }
}