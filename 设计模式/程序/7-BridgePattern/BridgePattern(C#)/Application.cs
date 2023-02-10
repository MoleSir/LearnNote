/* C# 实现桥接模式 */
using System;

namespace BridgePattern
{
    /* 创建桥接实现接口 *************************************************/
    public interface DrawAPI
    {
        void drawCircle(int radius, int x, int y);
    }


    /* 创建实现了 DrawAPI 接口的实体桥接实现类 ***************************/
    public class RedCircle: DrawAPI
    {
        public void drawCircle(int radius, int x, int y)
        {
            Console.WriteLine("Draw Red Circle in (x = {0}, y = {1}) with radius {2}", 
                              x, y, radius);
        }
    }

    public class GreenCircle: DrawAPI
    {
        public void drawCircle(int radius, int x, int y)
        {
            Console.WriteLine("Draw Green Circle in (x = {0}, y = {1}) with radius {2}", 
                              x, y, radius);
        }
    }


    /* 使用 DrawAPI 接口创建抽象类 Shape ***********************************/
    public abstract class Shape
    {   
        public Shape(DrawAPI api)
        {
            drawAPI = api;
        }
        public abstract void draw();
        protected  DrawAPI drawAPI;
    }


    /* 创建实现了 Shape 抽象类的实体类 *****************************************/
    public class Circle: Shape
    {
        public Circle(int x, int y, int r, DrawAPI drawAPI): base(drawAPI)
        {
            this.x = x;
            this.y = y;
            this.radius = r;
        }
        public override void draw()
        {
            drawAPI.drawCircle(radius, x, y);
        }
        private int x;
        private int y;
        private int radius;
    }

    

    class Program
    {
        static void Main(string[] args)
        {
            Shape redCircle = new Circle(100,100, 10, new RedCircle());
            Shape greenCircle = new Circle(100,100, 10, new GreenCircle());
        
            redCircle.draw();
            greenCircle.draw();
        }
    }
}