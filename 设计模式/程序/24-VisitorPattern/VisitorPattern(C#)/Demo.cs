using System;

namespace VisitorPatternApp
{
    class Program
    {
        static void Main()
        {
            // 创建对象
            Keyboard keyboard = new Keyboard();
            Monitor monitor = new Monitor();
            Mouse mouse = new Mouse();
            ComputerPartDisplayVisitor displayVisitor = new ComputerPartDisplayVisitor();
            ComputerPartFixVisitor fixVisitor = new ComputerPartFixVisitor();

            // 使用显示访问器
            keyboard.Accept(displayVisitor);
            mouse.Accept(displayVisitor);
            
            // 使用修复访问器
            keyboard.Accept(fixVisitor);
            mouse.Accept(fixVisitor);
            monitor.Accept(fixVisitor);
        }
    }
}