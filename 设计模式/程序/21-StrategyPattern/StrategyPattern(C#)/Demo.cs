/* C# 实现策略模式 */
using System;

namespace StrategyPatternApp
{
    public interface Operation
    {
        int Operate(int number1, int number2);
    }

    public class AddOperation : Operation
    {
        public int Operate(int number1, int number2)
        {
            return number1 + number2;
        }
    }

    public class SubOperation : Operation
    {
        public int Operate(int number1, int number2)
        {
            return number1 - number2;
        }
    }
    public class MulOperation : Operation
    {
        public int Operate(int number1, int number2)
        {
            return number1 * number2;
        }
    }

    class Calculator
    {
        public Calculator(Operation operation)
        {
            this.operation = operation;
        }
        public int Calculate(int number1, int number2)
        {
            return this.operation.Operate(number1, number2);
        }
        public void SetOperation(Operation operation)
        {
            this.operation = operation;
        }
        private Operation operation;
    }

    class Program
    {
        static void Main()
        {
            Operation adder = new AddOperation();
            Operation subber = new SubOperation();
            Operation muller = new MulOperation();

            Calculator calculator = new Calculator(adder);   

            Console.WriteLine("10 + 20 = {0}", calculator.Calculate(10, 20));

            calculator.SetOperation(subber);
            Console.WriteLine("20 - 15 = {0}", calculator.Calculate(20, 15));

            calculator.SetOperation(muller);
            Console.WriteLine("10 * 20 = {0}", calculator.Calculate(10, 20));
        }
    }
}