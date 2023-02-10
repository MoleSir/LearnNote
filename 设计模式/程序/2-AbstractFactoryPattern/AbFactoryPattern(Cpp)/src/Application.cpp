/* 使用 c++ 实现抽象工厂模式 */
#include "AbstractFactory.h"
#include <iostream>
#include <string>
using namespace AbstratFactoryPattern;


/* 使用抽象工厂 */
int main()
{    // 使用抽象工厂选择工厂
    // 创建了一个颜色工厂
    AbstractFactory* colorFactory = GetFactory("COLOR");
    // 使用颜色工厂创建颜色
    Color* color1 = colorFactory->GetColor("Red");
    Color* color2 = colorFactory->GetColor("Green");
    // 使用颜色
    color1->fill();
    color2->fill();

    // 创建了一个形状工厂
    AbstractFactory* shapeFactory = GetFactory("SHAPE");
    // 使用形状工厂创建形状
    Shape* shape1 = shapeFactory->GetShape("Circle");
    Shape* shape2 = shapeFactory->GetShape("Square");
    // 使用形状
    shape1->draw();
    shape2->draw();

    // 释放
    delete colorFactory;
    delete shapeFactory;
    delete color1;
    delete color2;
    delete shape1;
    delete shape2;

    return 0;
}