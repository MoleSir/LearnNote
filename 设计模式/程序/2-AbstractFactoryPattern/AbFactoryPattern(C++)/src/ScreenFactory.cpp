#include "ScreenFactory.h"
#include <string>
#include <iostream>


namespace ComputerMaking
{
    Screen::~Screen()
    { }

    void HuaweiScreen::Display(const std::string& content)
    {
        std::cout << "Huawei Screen Display: " << content << std::endl;
    }

    void AppleScreen::Display(const std::string& content)
    {
        std::cout << "Apple Screen Display: " << content << std::endl;
    }

    void XiaomiScreen::Display(const std::string& content)
    {
        std::cout << "Xiaomi Screen Display: " << content << std::endl;
    }


    ScreenFactory::~ScreenFactory()
    {}

    Screen* HuaweiScreenFactory::GetScreen()
    {
        return new HuaweiScreen();
    }

    Screen* AppleScreenFactory::GetScreen()
    {
        return new AppleScreen();
    }

    Screen* XiaomiScreenFactory::GetScreen()
    {
        return new XiaomiScreen();
    }
}