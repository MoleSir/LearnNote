#include "ShapeFactory.h"
#include "ColorFactory.h"

#include <iostream>
#include <string>


namespace AbstratFactoryPattern
{
    void Rectangle::draw()
    {
        std::cout << "draw a Rectangle" << std::endl;
    }

    void Circle::draw()
    {
        std::cout << "draw a Circle" << std::endl;
    }

    void Square::draw()
    {
        std::cout << "draw a Square" << std::endl;
    }


    /**********************************************************
     * @brief ShapeFactory's GetColor
     * @param shapeType shape need to create
     * @return Shape* object point
     **********************************************************/
    Shape* ShapeFactory::GetShape(const std::string& shapeType) 
    {
        if (shapeType == "Rectangle")
            return new Rectangle();
        else if (shapeType == "Circle")
            return new Circle();
        else if (shapeType == "Square")
            return new Square();
        return nullptr;
    }

    /**********************************************************
     * @brief ShapeFactory's GetColor
     * @param colorType color need to create
     * @return Color* object point
     **********************************************************/
    Color* ShapeFactory::GetColor(const std::string& colorType)
    {
        return nullptr;
    }
}