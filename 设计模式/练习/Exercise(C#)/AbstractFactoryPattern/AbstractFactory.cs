/* 抽象工厂基类 */
namespace AbstractFactoryPatternApplication
{
    public interface AbstractFactory
    {
        // 获取 A 类产品
        AbstractProductA CreateProductA();

        // 获取 B 类产品
        AbstractProductB CreateProductB();
    }
}