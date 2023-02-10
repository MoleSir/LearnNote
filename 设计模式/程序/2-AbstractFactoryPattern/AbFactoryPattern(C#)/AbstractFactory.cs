using System;


namespace AbstractFactoryPattern
{
    public interface AbstractFactory
    {
        Color GetColor(string colorType);
        Shape GetShape(string shapeType);
    }

    public class FactoryMaker
    {
        public AbstractFactory GetFactory(string factoryType)
        {
            if (factoryType == "COLOR")
                return new ColorFactory();
            else if (factoryType == "SHAPE")
                return new ShapeFactory();
            else 
                return null;
        }
    }
}