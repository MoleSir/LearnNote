using System;

namespace StatePatternApp
{
    /* 基类 */
    public interface State
    {
        void DoOperation1(string message);
        void DoOperation2(string message);
        void DoOperation3(string message);
    }

    /* 子类 */
    public class StateA : State
    {
        public void DoOperation1(string message)
        {
            Console.WriteLine("Do Operation1 at State A with {0}", message);
        }
        public void DoOperation2(string message)
        {
            Console.WriteLine("Do Operation2 at State A with {0}", message);
        }
        public void DoOperation3(string message)
        {
            Console.WriteLine("Do Operation3 at State A with {0}", message);
        }
    }

    public class StateB : State
    {
        public void DoOperation1(string message)
        {
            Console.WriteLine("Do Operation1 at State B with {0}", message);
        }
        public void DoOperation2(string message)
        {
            Console.WriteLine("Do Operation2 at State B with {0}", message);
        }
        public void DoOperation3(string message)
        {
            Console.WriteLine("Do Operation3 at State B with {0}", message);
        }
    }

    public class StateC : State
    {
        public void DoOperation1(string message)
        {
            Console.WriteLine("Do Operation1 at State C with {0}", message);
        }
        public void DoOperation2(string message)
        {
            Console.WriteLine("Do Operation2 at State C with {0}", message);
        }
        public void DoOperation3(string message)
        {
            Console.WriteLine("Do Operation3 at State C with {0}", message);
        }
    }
}