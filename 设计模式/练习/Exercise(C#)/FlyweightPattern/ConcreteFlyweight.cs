/* Flyweight 子类实现 */
using System;
using System.Runtime.InteropServices;

namespace FlyweightPatternApplication
{
    public class ConcreteFlyweight : Flyweight
    {
        // 构造函数
        public ConcreteFlyweight(string intrinsicState)
        {
            this.intrinsicState = intrinsicState;
        }
        
        // 获取地址
        private static string GetMemory(object o) // 获取引用类型的内存地址方法
        {
            GCHandle h = GCHandle.Alloc(o, GCHandleType.Pinned);
            IntPtr addr = h.AddrOfPinnedObject();
            return addr.ToString("X");
        }

        // 实现接口
        public void DoOperation(string extrinsicState)
        {
            Console.WriteLine("Object address: 0x{0}", GetMemory(this));
            Console.WriteLine("IntrinsicState: {0}", this.intrinsicState);
            Console.WriteLine("ExtrinsicState: {0}", extrinsicState);
        }

        // 内部状态标识
        private string intrinsicState;
    }
}