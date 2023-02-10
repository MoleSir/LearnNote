using System;

namespace DecoratorPattern
{
    public abstract class ShapeDecorator : Shape
    {   
        protected Shape shape;
        public ShapeDecorator(Shape shape)
        {
            this.shape = shape;
        }
        public virtual void draw()
        {
            shape.draw();
        }
    } 
    
    public class ColorShape: ShapeDecorator
    {
        protected string color;
        public ColorShape(Shape shape, string color): base(shape)
        {
            this.color = color;
        }
        public override void draw()
        {
            shape.draw();
            Console.WriteLine("With {0} Color", this.color);
        }
    }
}