/* 生产产品2的工厂 */
namespace FactoryPattenApplication
{
    public class ConcreteFactory2 : Factory
    {
        // 实现接口
        public Product CreateProfuct(string message)
        {
            return new ConcreteProduct2(message);
        }
    }
}