/* 叶子节点 */
using System;
using System.Collections.Generic;

namespace CompositePatternApplication
{
    public class Leaf : Component
    {
        // 构造函数
        public Leaf(string name) : base(name) {}

        // 实现抽象函数
        public override void PrintImp(int level)
        {
            // 根据等级打印 -- 
            for (int i = 0; i < level; ++i)
                Console.Write("--");
            // 打印自身信息
            Console.WriteLine(this.name);
        }
    }
}