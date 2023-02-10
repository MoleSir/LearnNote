/* C++ 实现状态模式 */
#include <iostream>
#include <string>

namespace StatePattern
{
    /* 状态操作基类 */
    class State
    {
    public:
        virtual void DoOperation1(const std::string& message) const = 0;
        virtual void DoOperation2(const std::string& message) const = 0;
        virtual void DoOperation3(const std::string& message) const = 0;
        virtual ~State() {}
    };

    /* 状态子类实现，单例 */
    class StateA : public State
    {
    private:
        StateA() {}

    public:
        virtual void DoOperation1(const std::string& message) const override
        {
            std::cout << "Do Operaotion1 at State A with " << message << std::endl; 
        }
        virtual void DoOperation2(const std::string& message) const override
        {
            std::cout << "Do Operaotion2 at State A with " << message << std::endl; 
        }
        virtual void DoOperation3(const std::string& message) const override
        {
            std::cout << "Do Operaotion2 at State A with " << message << std::endl; 
        }

        static StateA* GetInstance()
        {
            if (StateA::_instance == nullptr)
            {
                StateA::_instance = new StateA();
            }
            return StateA::_instance;
        } 

    private:
        static StateA* _instance;
    };

    StateA* StateA::_instance = nullptr;

    class StateB : public State
    {
    private:
        StateB() {}

    public:
        virtual void DoOperation1(const std::string& message) const override
        {
            std::cout << "Do Operaotion1 at State B with " << message << std::endl; 
        }
        virtual void DoOperation2(const std::string& message) const override
        {
            std::cout << "Do Operaotion2 at State B with " << message << std::endl; 
        }
        virtual void DoOperation3(const std::string& message) const override
        {
            std::cout << "Do Operaotion2 at State B with " << message << std::endl; 
        }

        static StateB* GetInstance()
        {
            if (StateB::_instance == nullptr)
            {
                StateB::_instance = new StateB();

            }
            return StateB::_instance;
        } 

    private:
        static StateB* _instance;
    };

    StateB* StateB::_instance = nullptr;

    class StateC : public State
    {
    private:
        StateC() {}

    public:
        virtual void DoOperation1(const std::string& message) const override
        {
            std::cout << "Do Operaotion1 at State C with " << message << std::endl; 
        }
        virtual void DoOperation2(const std::string& message) const override
        {
            std::cout << "Do Operaotion2 at State C with " << message << std::endl; 
        }
        virtual void DoOperation3(const std::string& message) const override
        {
            std::cout << "Do Operaotion2 at State C with " << message << std::endl; 
        }

        static StateC* GetInstance()
        {
            if (StateC::_instance == nullptr)
            {
                StateC::_instance = new StateC();
            }
            return StateC::_instance;
        } 

    private:
        static StateC* _instance;
    };

    StateC* StateC::_instance = nullptr;

    /* subject类 */
    class Subject
    {
    public:
        Subject(State* state): _state(state)
        {}
        void SetState(State* state)
        {
            this->_state = state;
        }
        // 操作
        void Operator1(const std::string& message) const
        {
            if (this->_state != nullptr)
                this->_state->DoOperation1(message);
        }
        void Operator2(const std::string& message) const
        {
            if (this->_state != nullptr)
                this->_state->DoOperation2(message);
        }
        void Operator3(const std::string& message) const
        {
            if (this->_state != nullptr)
                this->_state->DoOperation3(message);
        }

    private:
        State* _state;
    };
}


int main()
{
    using namespace StatePattern;

    // 获取三种状态对象
    StateA* a = StateA::GetInstance();
    StateB* b = StateB::GetInstance();
    StateC* c = StateC::GetInstance();

    Subject subject(a);
    subject.Operator1("hhhhh");

    subject.SetState(b);
    subject.Operator2("yyyyy");

    subject.SetState(c);
    subject.Operator3("xxxxx");

    delete a;
    delete b;
    delete c;

    return 0;
}