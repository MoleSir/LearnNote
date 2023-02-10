using System;

namespace VisitorPatternApp
{
    public interface ComputerPartVisitor
    {
        // 这里的话，用一样的函数名称，因为参数类型不同
        void Visit(Keyboard keyboard);
        void Visit(Monitor monitor);
        void Visit(Mouse mouse);
    }
}
