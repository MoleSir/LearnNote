using System;

namespace VisitorPatternApp
{
    /* 电脑部件基类 */  
    public interface ComputerPart
    {
        void Accept(ComputerPartVisitor visitor);
    }

    /* 电脑部件实现 */
    public class Keyboard : ComputerPart
    {
        public void Accept(ComputerPartVisitor visitor)
        {
            visitor.Visit(this);
        }
    }

    public class Monitor : ComputerPart
    {
        public void Accept(ComputerPartVisitor visitor)
        {
            visitor.Visit(this);
        }
    }

    public class Mouse : ComputerPart
    {
        public void Accept(ComputerPartVisitor visitor)
        {
            visitor.Visit(this);
        }
    }
}