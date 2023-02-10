/* C++ 实现外观模式 */
#include <iostream>
#include <string>


namespace FacadePattern
{
    /* 接口 */
    class Shape
    {
    public:
        virtual void draw() = 0;
    };

    /* 实现 */
    class Circle : public Shape
    {
    public:
        virtual void draw() override
        {
            std::cout << "Draw a Circle!" << std::endl;
        }
    };  

    class Square : public Shape
    {
    public:
        virtual void draw() override
        {
            std::cout << "Draw a Square!" << std::endl;
        }
    };  

    class Rectangle : public Shape
    {
    public:
        virtual void draw() override
        {
            std::cout << "Draw a Rectangle!" << std::endl;
        }
    };  

    /* 外观类 */
    class ShapeMaker
    {
    public:
        ShapeMaker()
        {
            this->_circle = new Circle();
            this->_rectangle = new Rectangle();
            this->_square = new Square();
        }
        ~ShapeMaker()
        {
            delete this->_circle;
            delete this->_rectangle;
            delete this->_square;
        }
        void DrawCircle() const 
        {
            this->_circle->draw();
        }
        void DrawRectangle() const
        {
            this->_rectangle->draw();
        }
        void DrawSquare() const 
        {
            this->_square->draw();
        }
    private:
        Shape* _circle;
        Shape* _rectangle;
        Shape* _square;
    };
}


int main()
{
    using namespace FacadePattern;
    ShapeMaker shapeMaker;
    shapeMaker.DrawCircle();
    shapeMaker.DrawRectangle();
    shapeMaker.DrawSquare();

    return 0;
}