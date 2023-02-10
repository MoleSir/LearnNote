/* C# 迭代器模式 */
using System;

namespace InteratorPatternApplication
{
    class Program
    {
        static void Main()
        {
            Aggregate<int> aggregate = new ConcreteAggregate<int>(12, 2);
            
            // 获取迭代器
            Iterator<int> iterator = aggregate.CreateIterator();

            // 输出
            while (iterator.HasNext())
            {
                Console.WriteLine(iterator.Next());
            }
        }
    }
}