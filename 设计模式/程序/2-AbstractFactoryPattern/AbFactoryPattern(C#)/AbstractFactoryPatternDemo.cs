using System;


namespace AbstractFactoryPattern
{
    class Program
    {
        static void Main(string[] args)
        {
            FactoryMaker factoryMaker = new FactoryMaker();
            AbstractFactory colorFactory = factoryMaker.GetFactory("COLOR");
            Color red = colorFactory.GetColor("RED");
            red.fill();

            AbstractFactory shapeFactoty = factoryMaker.GetFactory("SHAPE");
            Shape rectangle = shapeFactoty.GetShape("RECTANGLE");
            rectangle.draw();
        }
    }
}