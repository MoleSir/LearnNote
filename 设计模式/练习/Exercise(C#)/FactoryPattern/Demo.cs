namespace FactoryPattenApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            ConcreteFactory1 factory1 = new ConcreteFactory1();
            Product product1 = factory1.CreateProfuct("#1");

            ConcreteFactory2 factory2 = new ConcreteFactory2();
            Product product2 = factory2.CreateProfuct("#2");
        }
    }
}