#ifndef __SCREEN_H__
#define __SCREEN_H__
#include <string>


namespace ComputerMaking
{
    /* 显示屏基类 */
    class Screen
    {
    public:
        virtual void Display(const std::string& content) = 0;
        virtual ~Screen();
    };

    /* 显示屏工厂 */
    class ScreenFactory
    {
    public:
        virtual Screen* GetScreen() = 0;
        virtual ~ScreenFactory();
    };

    /* 实现类 */
    class HuaweiScreen : public Screen
    {
    public:
        virtual void Display(const std::string& content) override;
    };

    class AppleScreen : public Screen
    {
    public:
        virtual void Display(const std::string& content) override;
    };

    class XiaomiScreen : public Screen
    {
    public:
        virtual void Display(const std::string& content) override;
    };

    /* 显示屏工厂实现类 */
    class HuaweiScreenFactory : public ScreenFactory
    {
    public:
        virtual Screen* GetScreen() override;
    };

    class AppleScreenFactory : public ScreenFactory
    {
    public:
        virtual Screen* GetScreen() override;
    };

    class XiaomiScreenFactory : public ScreenFactory
    {
    public:
        virtual Screen* GetScreen() override;
    };
}



#endif