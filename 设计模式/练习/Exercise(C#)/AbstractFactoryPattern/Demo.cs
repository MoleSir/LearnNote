/*
* 一个抽象工厂的小例子，有两种产品 A, B，每个产品都有 1 产家与 2 产假
* 我们希望 1 工厂只生产 1 产家的 A,B 产品
*  2 工厂只生产 2 产家的 A,B 产品
*/
namespace AbstractFactoryPatternApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            AbstractFactory abstractFactory = new ConcreteFactory1();
            AbstractProductA productA = abstractFactory.CreateProductA();
            AbstractProductB productB = abstractFactory.CreateProductB();
        }
    }
}