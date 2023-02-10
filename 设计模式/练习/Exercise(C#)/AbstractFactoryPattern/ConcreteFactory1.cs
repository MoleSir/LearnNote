/* 只生产 1 牌产品 */
namespace AbstractFactoryPatternApplication
{
    public class ConcreteFactory1 : AbstractFactory 
    {
        // 获取 A 类产品
        public AbstractProductA CreateProductA()
        {
            return new ProductA1();
        }

        // 获取 B 类产品
        public AbstractProductB CreateProductB()
        {
            return new ProductB1();
        }
    }
}