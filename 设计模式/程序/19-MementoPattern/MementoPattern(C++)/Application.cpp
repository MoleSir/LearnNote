/* 使用 C++ 实现备忘录模式 */
#include <iostream>
#include <string>
#include <vector>


namespace MementoPatternApp
{
    /* 创建 Memento 类，用来保存状态*/ 
    class Memento
    {
    public:
        Memento(const std::string& state) : _state(state)
        {}
        std::string GetState() const 
        {
            return this->_state;
        }
    private:
        std::string _state;
    };

    /* 创建 Originator 类，需要版本控制的类 */
    class Originator
    {
    public: 
        Originator() : _state("")
        { }
        void SetState(const std::string& state)
        {
            this->_state = state;
        }
        std::string GetState() const
        {
            return this->_state;
        }
        // 获取当前状态，保存到一个备忘录中
        Memento* SaveStateToMemento() const
        {
            return new Memento(this->_state);
        }
        // 从某个备忘录中恢复状态
        void GetStateFromMemento(Memento* memento)
        {
            this->_state = memento->GetState();
        }
    private:
        std::string _state;
    };

    /* 创建 CareTaker 类，保存往期状态的类 */
    class CareTaker
    {
    public:
        CareTaker() : _memento()
        {}
        void Add(Memento* memento)
        {
            this->_memento.push_back(memento);
        }
        Memento* Get(int index)
        {
            return this->_memento[index];
        }
    private:
        std::vector<Memento*> _memento;
    };
}


int main()
{
    using namespace MementoPatternApp;

    Originator originator;
    CareTaker careTaker;

    originator.SetState("State #1");
    originator.SetState("State #2");

    // 保存状态
    careTaker.Add(originator.SaveStateToMemento());

    // 改变状态
    originator.SetState("State #3");

    // 再保存
    careTaker.Add(originator.SaveStateToMemento());

    // 再改变状态
    originator.SetState("State #4");

    // 输出当前状态
    std::cout << "Current State: " << originator.GetState() << std::endl;
    
    // 恢复第0个保存状态
    originator.GetStateFromMemento(careTaker.Get(0));
    std::cout << "First Saved State: " << originator.GetState() << std::endl;

    // 恢复第1个保存状态
    originator.GetStateFromMemento(careTaker.Get(1));
    std::cout << "Second Saved State: " << originator.GetState() << std::endl;

    return 0;
}