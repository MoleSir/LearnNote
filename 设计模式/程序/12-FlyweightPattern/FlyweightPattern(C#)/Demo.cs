/* C# 实现享元模式 */
using System;
using System.Collections.Generic;

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
        public void draw()
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
        public ShapeFactory()
        {
            this.shapeDict = new Dictionary<string, Shape>();
        }

        /* 工厂函数 */
        public Shape GetShape(string shapeType)
        {
            // 检查是否存在产品
            if (this.shapeDict.ContainsKey(shapeType))
                return this.shapeDict[shapeType];
            
            // 不存在需要自己创建
            Shape shape = null;
            if (shapeType == "Rectangle")
                shape =  new Rectangle();
            else if (shapeType == "Circle")
                shape =  new Circle();
            else if (shapeType == "Square")
                shape =  new Square();
            else 
                Console.WriteLine("No this Type of Shape");
            
            // 添加
            if (shape != null)
                this.shapeDict.Add(shapeType, shape);

            return shape;
        }

        // 保存对象的字典
        private Dictionary<string, Shape> shapeDict;
    }
    

    class Program
    {
        static void Main(string[] args)
        {
            ShapeFactory shapeFactory = new ShapeFactory();
            Shape shape1 = shapeFactory.GetShape("Rectangle");
            Shape shape2 = shapeFactory.GetShape("Square");
            Shape shape3 = shapeFactory.GetShape("Rectangle");

            Console.WriteLine("shape1 == shape3 ? {0}", shape1 == shape3);

            shape1.draw();
            shape2.draw();
        }
    }
}