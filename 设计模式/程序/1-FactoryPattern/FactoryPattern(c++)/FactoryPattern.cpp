#include <iostream>
#include <string>

/* C++实现工厂模式 */
namespace ShapeFactory
{
    /* 接口类 */
    class Shape
    {
    public:
        virtual void draw() = 0;
        virtual Shape(){}
    };

    /* 正方形类 */
    class Rectangle: public Shape
    {
    public:
        virtual void draw() override
        {
            std::cout << "draw a Rectangle" << std::endl;
        }
    };

    /* 圆形 */
    class Circle: public Shape
    {
    public:
        virtual void draw() override
        {
            std::cout << "draw a Circle" << std::endl;
        }
    };

    /* 正方形 */
    class Square: public Shape
    {
    public:
        virtual void draw() override
        {
            std::cout << "draw a Square" << std::endl;
        }
    };

    /* 工厂函数 */
    Shape* GetShape(const std::string& shapeType)
    {
        if (shapeType == "Rectangle")
            return new Rectangle();
        else if (shapeType == "Circle")
            return new Circle();
        else if (shapeType == "Square")
            return new Square();
        return nullptr;
    }
}


int main()
{
    /* 使用工厂函数 */
    ShapeFactory::Shape* shape1 = ShapeFactory::GetShape("Rectangle");
    ShapeFactory::Shape* shape2 = ShapeFactory::GetShape("Circle");

    shape1->draw();
    shape2->draw();

    delete shape1;
    delete shape2;

    return 0;
}
