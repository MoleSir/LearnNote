/* 访问者实现 */
using System;

namespace VisitorPatternApplication
{
    public class GeneralReport : Visitor
    {
        public GeneralReport()
        {
            this.customersNum = 0;
            this.ordersNum = 0;
            this.itemsNum = 0;
        } 

        public void Visit(Item item)
        {
            Console.WriteLine("Item name: {0}", item.GetName());
            this.itemsNum++;
        }

        public void Visit(Order order)
        {
            Console.WriteLine("Order name: {0}", order.GetName());
            this.ordersNum++;
        }

        public void Visit(Customer customer)
        {
            Console.WriteLine("Customer name: {0}", customer.GetName());
            this.customersNum++;
        }


        public void DisplayResults() 
        {
            Console.WriteLine("Number of customers: " + this.customersNum);
            Console.WriteLine("Number of orders:    " + this.ordersNum);
            Console.WriteLine("Number of items:     " + this.itemsNum);
        }

        // 记录访问过的个数
        private int customersNum;
        private int ordersNum;
        private int itemsNum;
    }
}