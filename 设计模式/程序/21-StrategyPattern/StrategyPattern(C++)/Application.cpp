/* C++ 策略模式 */
#include <iostream>
#include <string>


namespace StrategyPattern
{
    class Operation
    {
    public:
        virtual int Operate(int number1, int number2) const = 0;
    };

    class AddOperation : public Operation
    {
    public:
        int Operate(int number1, int number2) const override
        {
            return number1 + number2;
        }
    };  

    class SubOperation : public Operation
    {
    public:
        int Operate(int number1, int number2) const override
        {
            return number1 - number2;
        }
    };  

    class MulOperation : public Operation
    {
    public:
        int Operate(int number1, int number2) const override
        {
            return number1 * number2;
        }
    };  

    class Calculator
    {
    public:
        Calculator(Operation* operation): _operation(operation)
        {}
        int Calculate(int number1, int number2) const
        {
            return this->_operation->Operate(number1, number2);
        }
        void SetOperation(Operation* operation)
        {
            this->_operation = operation;
        }
    private:
        Operation* _operation;
    };
}

int main()
{
    using namespace StrategyPattern;

    Operation* adder = new AddOperation();
    Operation* subber = new SubOperation();
    Operation* muller = new MulOperation();

    Calculator calculator(adder);
    std::cout << "10 + 20 = " << calculator.Calculate(10, 20) << std::endl;

    calculator.SetOperation(subber);
    std::cout << "20 - 15 = " << calculator.Calculate(20, 15) << std::endl;

    calculator.SetOperation(muller);
    std::cout << "10 * 20 = " << calculator.Calculate(10, 20) << std::endl;

    delete adder;
    delete subber;
    delete muller;
    return 0;
}