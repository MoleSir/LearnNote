/* C++ 实现享元模式 */
#include <iostream>
#include <string>
#include <map>


namespace FlyweightPattern
{
    /* 基类接口 */
    class Shape
    {
    public:
        Shape(const std::string& color): _color(color)
        {}
        virtual void draw() = 0;
    protected:
        std::string _color;
    };

    /* 实现 */
    class Circle : public Shape
    {
    public:
        Circle(const std::string& color): Shape(color)
        {}
        virtual void draw() override
        {
            std::cout << "Draw a " << this->_color << " Circle" << std::endl;
        }
    };

    class Rectangle : public Shape
    {
    public:
        Rectangle(const std::string& color): Shape(color)
        {}
        virtual void draw() override
        {
            std::cout << "Draw a " << this->_color << " Rectangle" << std::endl;
        }
    };


    /* 工厂 */
    class ShapeFactory
    {   
    public:
        // 析构函数负责释放内存资源
        ~ShapeFactory()
        {
            for (auto iter = this->_shapeMap.begin(); iter != this->_shapeMap.end(); iter++)
                delete iter->second;
        }
        Shape* GetShape(const std::string& color, const std::string& shape)
        {
            std::string key = color + shape;
            // 检查此 key 对于的 shape 是否存在
            auto iter = this->_shapeMap.find(key);
            if (iter != this->_shapeMap.end())
            {
                std::cout << "Use a Shape Object already exists!" << std::endl;
                return iter->second;
            }
            
            // 不存在就创建
            Shape* newShape = nullptr;
            if (shape == "Circle")
                newShape = new Circle(color);
            else if (shape == "Rectangle")
                newShape = new Rectangle(color);
            else
                std::cout << "No this Shape! Fail to Create!" << std::endl;

            if (newShape != nullptr) 
            {
                this->_shapeMap.insert(std::pair<std::string, Shape*>(key, newShape));
                std::cout << "Create a new Shape Object!" << std::endl;
            }
            return newShape;
        }

        // 显示所有已经存在的形状
        void ShowAllShapeObjects() const 
        {
            std::cout << "Show All Shape Objects!" << std::endl;
            for (auto iter = this->_shapeMap.begin(); iter != this->_shapeMap.end(); iter++)
                iter->second->draw();
        }

    private:
        std::map<std::string, Shape*> _shapeMap;
    };
}


int main()
{
    using namespace FlyweightPattern;
    
    // 创建一个工厂
    ShapeFactory* shapeFactory = new ShapeFactory();

    // 获得形状
    Shape* redCircle = shapeFactory->GetShape("Red", "Circle");
    Shape* blueCircle = shapeFactory->GetShape("Blue", "Circle");
    Shape* greenRectangle = shapeFactory->GetShape("Green", "Rectangle");
    Shape* yellowRectangle = shapeFactory->GetShape("Yellow", "Rectangle");
    Shape* redCircle1 = shapeFactory->GetShape("Red", "Circle");

    // 检查
    shapeFactory->ShowAllShapeObjects();
    std::cout << (redCircle == redCircle1) << std::endl;

    delete shapeFactory;

    return 0;
}