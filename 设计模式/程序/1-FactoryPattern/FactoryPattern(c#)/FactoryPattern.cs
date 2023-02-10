/* 工厂模式C#实现 */
using System;

namespace ShapeFactory
{
    /* 接口 */
    interface Shape
    {   
        void draw();
    }

    /* 正方形 */
    class Rectangle: Shape
    {
        // 继承接口的函数不用加 override, 只有 vritual 与 override 搭配
        public /* override */ void draw()
        {
            Console.WriteLine("draw a Rectangle");
        }
    }

    /* 圆 */
    class Circle: Shape
    {
        public void draw()
        {
            Console.WriteLine("draw a Circle");
        }
    }

    /* 正方形 */
    class Square: Shape
    {
        public void draw()
        {
            Console.WriteLine("draw a Square");
        }
    }

    class ShapeFactory
    {
        /* 工厂函数 */
        public Shape GetShape(string shapeType)
        {
            if (shapeType == "Rectangle")
                return new Rectangle();
            else if (shapeType == "Circle")
                return new Circle();
            else if (shapeType == "Square")
                return new Square();
            return null;
        }

        static void Main(string[] args)
        {
            ShapeFactory shapeFactory = new ShapeFactory();
            Shape shape1 = shapeFactory.GetShape("Rectangle");
            Shape shape2 = shapeFactory.GetShape("Square");

            shape1.draw();
            shape2.draw();
        }
    }
}