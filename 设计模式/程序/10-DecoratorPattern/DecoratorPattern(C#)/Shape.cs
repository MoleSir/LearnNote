using System;


namespace DecoratorPattern
{
    public interface Shape
    {
        void draw();
    }

    public class Circle : Shape
    {
        public void draw()
        {
            Console.WriteLine("Draw a Circle");
        }
    }

    public class Rectangle : Shape
    {
        public void draw()
        {
            Console.WriteLine("Draw a Rectangle");
        }
    }
}