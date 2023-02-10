#include "KeyboradFactory.h"
#include <string>
#include <iostream>


namespace ComputerMaking
{
    Keyboard::~Keyboard()
    {}

    std::string HuaweiKeyborad::Typewrite()
    {
        std::string str;
        std::cout << "Use Huawei Keyborad to Typewrite: ";
        std::cin >> str;
        return std::move(str);
    }

    std::string AppleKeyborad::Typewrite()
    {
        std::string str;
        std::cout << "Use Apple Keyborad to Typewrite: ";
        std::cin >> str;
        return std::move(str);
    }

    std::string XiaomiKeyborad::Typewrite()
    {
        std::string str;
        std::cout << "Use Xiaomi Keyborad to Typewrite: ";
        std::cin >> str;
        return std::move(str);
    }


    KeyboardFactory::~KeyboardFactory()
    {}

    Keyboard* HuaweiKeyboardFactory::GetKeyborad()
    {
        return new HuaweiKeyborad();
    }

    Keyboard* AppleKeyboardFactory::GetKeyborad()
    {
        return new AppleKeyborad();
    }

    Keyboard* XiaomiKeyboardFactory::GetKeyborad()
    {
        return new XiaomiKeyborad();
    }
}