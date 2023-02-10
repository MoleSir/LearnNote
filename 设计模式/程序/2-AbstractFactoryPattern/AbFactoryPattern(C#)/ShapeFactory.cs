/* 形状工厂 */
using System;


namespace AbstractFactoryPattern
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

    public class Rectangle : Shape
    {
        public void draw()  
        {
            Console.WriteLine("Draw a Rectangle!"); 
        }
    }

    public class ShapeFactory : AbstractFactory
    {
        public Color GetColor(string colorType)
        { 
            return null;
        }
        public Shape GetShape(string shapeType)
        {
            if (shapeType == "CIRCLE")
                return new Circle();
            else if (shapeType == "RECTANGLE")
                return new Rectangle();
            else 
                return null;
        }
    }
}
