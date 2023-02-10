/*
* 以下是一个规则检验器实现，具有 and 和 or 规则，
* 通过规则可以构建一颗解析树，用来检验一个文本是否满足解析树定义的规则。
* 例如一颗解析树为 D And (A Or (B Or C))，文本 "D A" 满足该解析树定义的规则。
* 这个解析树的意义就是： D 并且 ((B 或 C) 或 A)
* 显然 D A 满足这个条件
*/
using System;

namespace InterpreterPatternApplication
{
    class Program
    {
        // 生成解析树
        static Expression BuildInterpreterTree()
        {
            // 四个终端表达式
            Expression terminal1 = new TerminalExpression("A");
            Expression terminal2 = new TerminalExpression("B");
            Expression terminal3 = new TerminalExpression("C");
            Expression terminal4 = new TerminalExpression("D");

            // 构造 B OR C
            Expression alternation1 = new OrExpression(terminal2, terminal3);

            // 构造 A OR (B OR C)
            Expression alternation2 = new OrExpression(terminal1, alternation1);

            // 构造 D AND (A OR (B OR C))
            Expression alternation3 = new AndExpression(terminal4, alternation2);

            return alternation3;
        }

        static void Main(string[] args)
        {
            Expression define = BuildInterpreterTree();

            string context1 = "D A";
            string context2 = "B A";

            Console.WriteLine(define.Interpret(context1));
            Console.WriteLine(define.Interpret(context2));
        }
    }
}