/* C++实现命令模式 */
#include <iostream>
#include <string>
#include <list>


namespace CommandPattern
{
    /* 基类 */
    class Command
    {
    public:
        virtual void excute() = 0;
        virtual ~Command() {}
    };

    /* 实现 */
    class Fork : public Command
    {
    public:
        Fork(const std::string& arg) : _arg(arg) {}
        // 实现基类虚函数
        virtual void excute() override
        {
            std::cout << "build the process: " << this->_arg << std::endl;
        }
    private:
        std::string _arg;
    };

    class Kill : public Command
    {
    public:
        Kill(const std::string& arg) : _arg(arg) {}
        // 实现虚函数
        virtual void excute() override
        {
            std::cout << "kill the process: " << this->_arg << std::endl;
        }
    private:
        std::string _arg;
    };

    /* 宏命令，整合多个命令 */
    class MacroCommad : public Command
    {
    public:
        MacroCommad() = default;
        //  添加命令
        void AddCommand(Command* command) 
        {
            this->_commands.push_back(command);
        }
        // 实现虚函数
        virtual void excute() override
        {
            // 以此执行命令
            for (Command* command : this->_commands)
            {
                command->excute();
            }
        }
    private:
        std::list<Command*> _commands;
    };
}


int main()
{
    using namespace CommandPattern;

    Fork fork("Hello");
    Kill kill("World");

    MacroCommad marco;
    marco.AddCommand(&fork);
    marco.AddCommand(&kill);

    marco.excute();

    return 0;
}