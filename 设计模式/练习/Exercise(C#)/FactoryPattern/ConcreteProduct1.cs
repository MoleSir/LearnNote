/* 产品子类1 */
using System;

namespace FactoryPattenApplication
{
    public class ConcreteProduct1 : Product
    {
        // 构造函数
        public ConcreteProduct1(string message) : base(message)
        {
            Console.WriteLine("Create a ConcreteProduct1");
        }
    }
}