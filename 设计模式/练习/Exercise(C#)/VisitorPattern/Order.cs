/* Element 的具体实现类，命令类 */
using System;
using System.Collections.Generic;

namespace VisitorPatternApplication
{
    public class Order : Element
    {
        // 构造函数
        public Order(string name)
        {
            this.name = name;
            this.items = new List<Item>();
        }
        public Order(string name, string itemName)
        {
            this.name = name;
            this.items = new List<Item>();
            this.items.Add(new Item(itemName));
        }

        public string GetName()
        {
            return this.name;
        }

        // 添加物品
        public void AddItem(Item item)
        {
            this.items.Add(item);
        }

        // 重写 Accept
        public void Accept(Visitor visitor)
        {
            // 访问自身
            visitor.Visit(this);

            // 依次访问所有物品
            foreach (Item item in this.items)
                item.Accept(visitor);
        }

        // 任务名称
        private string name;
        // 每个任务中有一个保存物品的列表
        private List<Item> items;
    }
}