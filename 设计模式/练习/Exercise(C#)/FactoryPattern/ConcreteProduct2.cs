/* 产品子类2 */
using System;

namespace FactoryPattenApplication
{
    public class ConcreteProduct2 : Product
    {
        // 构造函数
        public ConcreteProduct2(string message) : base(message)
        {
            Console.WriteLine("Create a ConcreteProduct2");
        }
    }
}