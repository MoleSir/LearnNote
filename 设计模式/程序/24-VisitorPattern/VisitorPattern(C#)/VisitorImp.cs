using System;

namespace VisitorPatternApp
{
    /* 显示访问器 */
    public class ComputerPartDisplayVisitor : ComputerPartVisitor
    {
        public void Visit(Keyboard keyboard)
        {
            Console.WriteLine("Display Keyboard");
        }
        public void Visit(Monitor monitor)
        {
            Console.WriteLine("Display Monitor");
        }
        public void Visit(Mouse mouse)
        {
            Console.WriteLine("Display Mouse");
        }   
    }

    /* 修理访问器 */
    public class ComputerPartFixVisitor : ComputerPartVisitor
    {
        public void Visit(Keyboard keyboard)
        {
            Console.WriteLine("Fix Keyboard");
        }
        public void Visit(Monitor monitor)
        {
            Console.WriteLine("Fix Monitor");
        }
        public void Visit(Mouse mouse)
        {
            Console.WriteLine("Fix Mouse");
        }   
    }
}