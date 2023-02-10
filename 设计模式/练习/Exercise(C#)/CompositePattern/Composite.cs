/* 树节点 */
using System;
using System.Collections.Generic;

namespace CompositePatternApplication
{
    public class Composite : Component
    {
        // 构造函数
        public Composite(string name) : base(name) 
        {
            this.children = new List<Component>();
        }

        // 添加孩子
        public void AddComponent(Component component)
        {
            this.children.Add(component);
        }

        // 移除孩子
        public bool RemoveComponent(Component component)
        {
            // 孩子在吗
            if (this.children.Contains(component) == true)
            {
                this.children.Remove(component);
                return true;
            }
            Console.WriteLine("Remove Fail");
            return false;
        }

        // 实现父类接口
        public override void PrintImp(int level)
        {
            // 根据等级打印 -- 
            for (int i = 0; i < level; ++i)
                Console.Write("--");
            // 打印自身信息
            Console.WriteLine(this.name);

            // 打印子树
            foreach (Component component in this.children)
                component.PrintImp(level + 1);
        }

        // 保存子树
        private List<Component> children;
    }
}