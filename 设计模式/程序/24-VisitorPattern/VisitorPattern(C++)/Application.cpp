/* C++ 实现访问者模式 */
#include <iostream>


namespace VisitorPatternApp
{
    /* 访问者基类 */
    class ComputerPartVisitor
    {
    public:
        // 针对所有电脑部件都需要给出一个接口
        virtual void VisitKeyborad(void* keyboardPtr) = 0;
        virtual void VisitMonitor(void* monitorPtr) = 0;
        virtual void VisitMouse(void* mousePtr) = 0;
    };

    /* 电脑部件基类 */
    class ComputerPart
    {
    public:
        // 为了方便拓展其中只有一个 Accept 函数，用来执行日后可拓展的功能
        virtual void Accept(ComputerPartVisitor* visitor) = 0;
    };

    /* 电脑部件实现类 */
    class Keyboard : public ComputerPart
    {
    public:
        virtual void Accept(ComputerPartVisitor* visitor) override
        {
            visitor->VisitKeyborad(this);
        }
    };

    class Monitor : public ComputerPart
    {
    public:
        virtual void Accept(ComputerPartVisitor* visitor) override
        {
            visitor->VisitMonitor(this);
        }
    };

    class Mouse : public ComputerPart
    {
    public:
        virtual void Accept(ComputerPartVisitor* visitor) override
        {
            visitor->VisitMouse(this);
        }
    };

    /* 访问者子类实现，也就是各种功能的拓展 */
    // 显示访问者
    class ComputerPartDisplayVisitor : public ComputerPartVisitor
    {
    public:
        virtual void VisitKeyborad(void* keyboardPtr) override
        {
            keyboardPtr = (Keyboard*)keyboardPtr;
            std::cout << "Display " << keyboardPtr << " Keyborad" << std::endl;  
        }
        virtual void VisitMonitor(void* monitorPtr) override
        {
            monitorPtr = (Monitor*)monitorPtr;
            std::cout << "Display " << monitorPtr << " Monitor" << std::endl;  
        }
        virtual void VisitMouse(void* mousePtr) override
        {
            mousePtr = (Mouse*)mousePtr;
            std::cout << "Display " << mousePtr << " Mouse" << std::endl; 
        }
    };

    // 显示访问器
    class ComputerPartFixVisitor : public ComputerPartVisitor
    {
    public:
        virtual void VisitKeyborad(void* keyboardPtr) override
        {
            keyboardPtr = (Keyboard*)keyboardPtr;
            std::cout << "Fix " << keyboardPtr << " Keyborad" << std::endl;  
        }
        virtual void VisitMonitor(void* monitorPtr) override
        {
            monitorPtr = (Monitor*)monitorPtr;
            std::cout << "Fix " << monitorPtr << " Monitor" << std::endl;  
        }
        virtual void VisitMouse(void* mousePtr) override
        {
            mousePtr = (Mouse*)mousePtr;
            std::cout << "Fix " << mousePtr << " Mouse" << std::endl; 
        }
    };
}

int main()
{
    using namespace VisitorPatternApp;
    
    // 使用修复访问器，只要在部件的 Accept 函数中传入需要进行的是什么操作即可
    ComputerPartFixVisitor fixVisitor;
    Keyboard keyboard;
    keyboard.Accept(&fixVisitor);
    Mouse mouse;
    mouse.Accept(&fixVisitor);

    // 使用显示访问器
    ComputerPartDisplayVisitor displayVisitor;
    Monitor monitor;
    monitor.Accept(&displayVisitor);
    mouse.Accept(&displayVisitor);
    keyboard.Accept(&displayVisitor);

    return 0;  
}