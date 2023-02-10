/* C# 实现外观模式 */
using System;


namespace FacadePattern
{
    public interface Shape
    {
        void draw();
    }
    
    public class Circle : Shape
    {
        public void draw()
        {
            Console.WriteLine("Draw a Circle!");
        }
    }
    public class Square : Shape
    {
        public void draw()
        {
            Console.WriteLine("Draw a Square!");
        }
    }
    public class Rectangle : Shape
    {
        public void draw()
        {
            Console.WriteLine("Draw a Rectangle!");
        }
    }

    public class ShapeMaker
    {
        public ShapeMaker()
        {
            this.circle = new Circle();
            this.rectangle = new Rectangle();
            this.square = new Square();
        }
        public void DrawCircle()
        {
            this.circle.draw();
        }
        public void DrawRectangle()
        {
            this.rectangle.draw();
        }
        public void DrawSquare()
        {
            this.square.draw();
        }
        private Shape circle;
        private Shape rectangle;
        private Shape square;
    }

    class Program
    {
        static void Main(string[] args)
        {
            ShapeMaker shapeMaker = new ShapeMaker();
            shapeMaker.DrawCircle();
            shapeMaker.DrawRectangle();
            shapeMaker.DrawSquare();
        }
    }
}