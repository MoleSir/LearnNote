/* 颜色工厂 */
using System;


namespace AbstractFactoryPattern
{
    public interface Color
    {
        void fill();
    }

    public class Red : Color
    {
        public void fill()
        {
            Console.WriteLine("Fill with Red!");
        }
    }

    public class Green : Color
    {
        public void fill()
        {
            Console.WriteLine("Fill with Green");
        }
    }

    /* 颜色的工厂类 */
    public class ColorFactory : AbstractFactory
    {   
        public Color GetColor(string colorType)
        {
            if (colorType == "RED")
                return new Red();
            else if (colorType == "GREEN")
                return new Green();
            else 
                return null;
        }
        public Shape GetShape(string shapeType)
        {
            return null;
        }
    }
}