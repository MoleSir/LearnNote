/* 只生产 2 牌产品的工厂 */
namespace AbstractFactoryPatternApplication
{
    public class ConcreteFactory2 : AbstractFactory 
    {
        // 获取 A 类产品
        public AbstractProductA CreateProductA()
        {
            return new ProductA2();
        }

        // 获取 B 类产品
        public AbstractProductB CreateProductB()
        {
            return new ProductB2();
        }
    }
}