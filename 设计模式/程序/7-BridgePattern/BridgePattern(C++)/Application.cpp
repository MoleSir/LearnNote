/* C++ 实现桥接模式 */
#include <iostream>
#include <string>


namespace BridgePattern
{
    /* 创建桥接实现接口 *************************************************/
    class DrawAPI
    {
    public:
        virtual void drawCircle(int radius, int x, int y) = 0;
    };


    /* 创建实现了 DrawAPI 接口的实体桥接实现类 ***************************/
    class RedCircle: public DrawAPI
    {
    public:
        virtual void drawCircle(int radius, int x, int y) override
        {
            std::cout << "Draw Red Circle in (x = " << x << ", y = " << y << ") whit radius: " 
                      << radius << std::endl;
        }
    };

    class GreenCircle: public DrawAPI
    {
    public:
        virtual void drawCircle(int radius, int x, int y) override
        {
            std::cout << "Draw Green Circle in (x = " << x << ", y = " << y << ") whit radius: " 
                      << radius << std::endl;
        }
    };


    /* 使用 DrawAPI 接口创建抽象类 Shape ***********************************/
    class Shape
    {
    public:
        Shape(DrawAPI* api): _drawAPI(api)
        {}
        virtual ~Shape()
        {}
        virtual void draw() = 0;
    protected:
        DrawAPI* _drawAPI;
    };


    /* 创建实现了 Shape 抽象类的实体类 *****************************************/
    class Circle: public Shape
    {
    public:
        Circle(DrawAPI* api, int x, int y, int radius): 
            Shape(api), _x(x), _y(y), _radius(radius)
        {}
        virtual ~Circle()
        {
            if (_drawAPI)
                delete _drawAPI;
        }
        virtual void draw() override
        {
            _drawAPI->drawCircle(_radius, _x, _y);
        }
    private:
        int _x, _y;
        int _radius;
    };
}


int main()
{
    using namespace BridgePattern;
    Shape* redCircle = new Circle(new RedCircle(), 100, 100, 10);
    Shape* greenCircle = new Circle(new GreenCircle(), 200, 200, 25);
    redCircle->draw();
    greenCircle->draw();
    delete redCircle;
    delete greenCircle;

    return 0;
}