/* C# 实现解释器模式 */
using System;

namespace InterpreterPattern
{
    class Program
    {
        static void Main(string[] arg)
        {
            // 是否为男
            Expression isMale = new TerminalExpression("Male");
            Console.WriteLine("John is Male? {0}", isMale.Interpret("John Male"));

            // 是否为男或者叫做 John
            Expression isJohn = new TerminalExpression("John");
            Expression isMaleOrJohn = new OrExpression(isMale, isJohn);
            Console.WriteLine("Tom is Jonh or Male? {0}", isMaleOrJohn.Interpret("Tom Female"));

            // 是否为女性并且已经婚
            Expression isFemale = new TerminalExpression("Female");
            Expression isMarried = new TerminalExpression("Married");
            Expression isFemaleAndMarried = new AndExpression(isFemale, isMarried);
            Console.WriteLine("Julie is a married-woman? {0}", isFemaleAndMarried.Interpret("Female Married"));
        }
    }
}