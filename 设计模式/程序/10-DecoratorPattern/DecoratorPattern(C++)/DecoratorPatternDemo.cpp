/* 用 C++ 实现菜鸟教程上的装饰器模式例子 */
#include <string>
#include <iostream>


namespace DecoratorStream
{
    /* 创建一个接口 ****************************************************/
    class Shape
    {
    public:
        virtual void draw() = 0;
    };


    /* 创建实现接口的实体类 *********************************************/
    class Circle : public Shape
    {
    public:
        virtual void draw()
        {
            std::cout << "Draw a Circle!" << std::endl;
        }
    };

    class Rectangle : public Shape
    {
    public:
        virtual void draw()
        {
            std::cout << "Draw a Rectangle!" << std::endl;
        }
    };
    /* 可以继续拓展更多的形状... */


    /* 创建实现了 Shape 接口的抽象装饰类，其本身也是一个接口 ****************/
    // 继承了 Shape 是为了得到其接口
    class ShapeDecorator : public Shape
    {
    protected:
        // 组合了一个 Shape* ，为了使用 Shape* 的功能，并且给其增加拓展
        // 既继承又组合，就是装饰器模式最显著的特征！
        Shape* _shape;
    public:
        ShapeDecorator(Shape* shape): _shape(shape)
        {}
    };


    /* 创建扩展了 ShapeDecorator 类的实体装饰类 ***************************/
    // 给绘制的外形增加上色功能
    class ColorShape : public ShapeDecorator
    {
    public:
        ColorShape(Shape* shape, const std::string& color): 
            ShapeDecorator(shape), _color(color)
        {}
        // 实现接口
        virtual void draw()
        {
            this->_shape->draw();
            std::cout << "with " << this->_color << " color!" << std::endl;
        }
    private:
        std::string _color;
    };
    /* 可以继续拓展，比如绘制有阴影的形状，只要继承 ShapeDecorator 即可使用 Shape 的功能，并且拥有其接口
       效果是看起来就像是另一个 Shape 的实体类，并且拥有了其他更多功能  */
}

int main()
{
    using namespace DecoratorStream;

    Shape* circle = new Circle();
    std::string red("RED");

    ShapeDecorator* redCircle = new ColorShape(circle, std::move(red));
    redCircle->draw();

    delete circle;
    delete redCircle;

    return 0;
}