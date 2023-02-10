#include "ColorFactory.h"
#include "ShapeFactoey.h"
#include <iostream>
#include <string>


namespace AbstratFactoryPattern
{
    void Red::fill()
    {
        std::cout << "fill with Red" << std::endl;
    }

    void Green::fill()
    {
        std::cout << "fill with Green" << std::endl;
    }
    

    /**********************************************************
     * @brief ColorFactory's GetColor
     * @param colorType color need to create
     * @return Color* object point
     **********************************************************/
    Color* ColorFactory::GetColor(const std::string& colorType)
    {
        if (colorType == "Red")
            return new Red();
        else if (colorType == "Green")
            return new Green();
        return nullptr;
    }

    /**********************************************************
     * @brief ColorFactory's GetShape
     * @param shapeType shape need to create
     * @return Color* object point
     **********************************************************/
    Shape* ColorFactory::GetShape(const std::string& shapeType)
    {
        return nullptr;
    }
}