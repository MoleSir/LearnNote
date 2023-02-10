using System;

namespace ObserverPatternApp
{
    /* 观察者基类 */
    public interface Observer
    {
        void Uptate(int newState);
    }

    /* 观察者子类实现 */
    public class BinaryObserver : Observer
    {
        public void Uptate(int newState)
        {
            Console.WriteLine("Binary String: {0}", Convert.ToString(newState, 2));
        }
    }

    public class OctalObserver : Observer
    {
        public void Uptate(int newState)
        {
            Console.WriteLine("Octal String: {0}", Convert.ToString(newState, 8));
        }
    }

    public class HexaObserver : Observer
    {
        public void Uptate(int newState)
        {
            Console.WriteLine("Hexa String: {0}", Convert.ToString(newState, 16));
        }
    }
}