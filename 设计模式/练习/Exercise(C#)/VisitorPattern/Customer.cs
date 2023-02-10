/* Element 的具体实现类，顾客类 */
using System;
using System.Collections.Generic;

namespace VisitorPatternApplication
{
    public class Customer : Element
    {
        // 构造函数
        public Customer(string name)
        {
            this.name = name;
            this.orders = new List<Order>();
        }

        public string GetName()
        {
            return this.name;
        }

        // 添加命令
        public void AddOrder(Order order)
        {
            this.orders.Add(order);
        }

        // 重写 Accept
        public void Accept(Visitor visitor)
        {
            // 先访问自己
            visitor.Visit(this);
            
            // 依次访问命令
            foreach (Order order in this.orders)
                order.Accept(visitor);
        }

        // 顾客名称
        private string name;
        // 保存顾客下达的命令列表
        private List<Order> orders;
    }
}