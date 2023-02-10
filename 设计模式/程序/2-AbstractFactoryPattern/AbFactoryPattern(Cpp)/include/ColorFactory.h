#ifndef __COLOR_H__
#define __COLOR_H__

#include "AbstractFactory.h"
#include <string>

namespace AbstratFactoryPattern
{
    class Color
    {
    public:
        virtual void fill() = 0;
    };

    class Red: public Color
    {
    public:
        virtual void fill() override;
    };

    class Green: public Color
    {
    public:
        virtual void fill() override;
    };

    /* 颜色的工厂类 */
    class AbstractFactory;
    class ColorFactory: public AbstractFactory
    {
    public:
        /* 颜色工厂函数 */
        virtual Color* GetColor(const std::string& colorType);
        /* 颜色工厂不生产Shape */
        virtual Shape* GetShape(const std::string& shapeType);
    };
}

#endif