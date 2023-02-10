/* 鸭子接口实现，家养鸭子 */
using System;

namespace AdapterPatternApplication
{
    public class DomesticDuck : Duck
    {
        public void Quack()
        {
            Console.WriteLine("Quack!!");
        }
    }
}