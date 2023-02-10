/* 访问者基类 */
namespace VisitorPatternApplication
{
    public interface Visitor
    {
        // 提供三个接口，对应三个 Element 子类
        void Visit(Item item);

        void Visit(Order order);

        void Visit(Customer customer);
    }
}