/* C# 实现访问者模式 */
namespace VisitorPatternApplication
{
    class Program
    {
        static void Main()
        {
            Customer customer1 = new Customer("customer1");
            customer1.AddOrder(new Order("order1", "item1"));
            customer1.AddOrder(new Order("order2", "item1"));
            customer1.AddOrder(new Order("order3", "item1"));

            Order order = new Order("order_a");
            order.AddItem(new Item("item_a1"));
            order.AddItem(new Item("item_a2"));
            order.AddItem(new Item("item_a3"));

            Customer customer2 = new Customer("customer2");
            customer2.AddOrder(order);

            GeneralReport visitor = new GeneralReport();
            customer1.Accept(visitor);
            customer2.Accept(visitor);

            visitor.DisplayResults();
        }
    }
}