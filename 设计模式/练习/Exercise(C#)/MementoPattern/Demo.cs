/*
* 实现了一个简单计算器程序，
* 可以输入两个值，然后计算这两个值的和。
* 备忘录模式允许将这两个值存储起来，然后在某个时刻用存储的状态进行恢复。 
*/
using System;

namespace MementoPatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            // 创建一个计算器
            Calculator calculator = new CalculatorImp(120, 340);
            // 创建 CareTaker
            PreviousCalculationToCareTaker careTaker = new PreviousCalculationToCareTaker();

            // 保存计算器当前状态
            careTaker.AddMemento("Status 1", calculator.BackupLastCalculation());

            // 修改状态
            calculator.SetFirstNumber(90);
            calculator.SetSecondNumber(89);

            // 保存状态
            careTaker.AddMemento("Status 2", calculator.BackupLastCalculation());

            // 修改状态
            calculator.SetFirstNumber(23);
            calculator.SetSecondNumber(1);

            // 保存状态
            careTaker.AddMemento("Status 3", calculator.BackupLastCalculation());


            // 恢复状态2
            calculator.RestorePreviousCalculation(careTaker.GetMemento("Status 2"));
            // 输出
            Console.WriteLine("Status 2 Output: {0}", calculator.GetCalculationResult());

            // 恢复状态1
            calculator.RestorePreviousCalculation(careTaker.GetMemento("Status 1"));
            // 输出
            Console.WriteLine("Status 1 Output: {0}", calculator.GetCalculationResult());

            // 恢复状态3
            calculator.RestorePreviousCalculation(careTaker.GetMemento("Status 3"));
            // 输出
            Console.WriteLine("Status 3 Output: {0}", calculator.GetCalculationResult());
        }
    }
}