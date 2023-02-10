#ifndef __FAC_H__
#define __FAC_H__

#include "ColorFactory.h"
#include "ShapeFactory.h"

#include <string>


namespace AbstratFactoryPattern
{
    /* 生产工厂的基类 */
    class AbstractFactory
    {
    public:
        virtual Color* GetColor(const std::string& colorType);
        virtual Shape* GetShape(const std::string& shapeType);
    };

    /* 抽象工厂的工厂函数 */
    AbstractFactory* GetFactory(const std::string& factoryType);
}


#endif