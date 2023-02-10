#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "AbstractFactory.h"
#include <string>

namespace AbstratFactoryPattern
{
    /* 形状接口类 */
    class Shape
    {
    public:
        virtual void draw() = 0;
    };

    /* 正方形类 */
    class Rectangle: public Shape
    {
    public:
        virtual void draw();
    };

    /* 圆形 */
    class Circle: public Shape
    {
    public:
        virtual void draw();
    };

    /* 正方形 */
    class Square: public Shape
    {
    public:
        virtual void draw();
    };

    /* 形状工厂类 */
    class AbstractFactory;
    class ShapeFactory: public AbstractFactory
    {
    public:
        /* 形状工厂函数 */
        virtual Shape* GetShape(const std::string& shapeType);
        /* 不生产颜色 */
        virtual Color* GetColor(const std::string& colorType);
    };
}

#endif