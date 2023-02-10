/* 生产产品1的工厂 */
namespace FactoryPattenApplication
{
    public class ConcreteFactory1 : Factory
    {
        // 实现接口
        public Product CreateProfuct(string message)
        {
            return new ConcreteProduct1(message);
        }
    }
}