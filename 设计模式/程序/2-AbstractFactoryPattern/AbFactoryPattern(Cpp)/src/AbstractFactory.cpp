#include "AbstractFactory.h"
#include "ColorFactory.h"
#include "ShapeFactory.h"

#include <iostream>
#include <string>


namespace AbstratFactoryPattern
{
    /*********************************************************
     * @brief Get the Factory object
     * @param factoryType: thefactory you need to create
     * @return AbstractFactory* the object pointer
     *********************************************************/
    AbstractFactory* GetFactory(const std::string& factoryType)
    {
        if (factoryType == "COLOR")
            return new ColorFactory;
        else if (factoryType == "SHAPE")
            return new ShapeFactory;
        return nullptr;
    }
}