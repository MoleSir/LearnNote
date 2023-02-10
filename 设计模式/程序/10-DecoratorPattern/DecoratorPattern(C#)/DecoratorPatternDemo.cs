using System;

namespace DecoratorPattern
{
    public class Program
    {
        static void Main(string[] args)
        {
            ShapeDecorator redCircle = new ColorShape(new Circle(), "RED");
            redCircle.draw();
        }
    }
}