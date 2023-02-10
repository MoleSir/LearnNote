#ifndef __KEYBORAD_H__
#define __KEYBORAD_H__
#include <string>


namespace ComputerMaking
{
    /* 键盘接口 */
    class Keyboard
    {
    public:
        virtual std::string Typewrite() = 0;
        virtual ~Keyboard();
    };

    /* 键盘工厂 */
    class KeyboardFactory
    {
    public:
        virtual Keyboard* GetKeyborad() = 0;
        virtual ~KeyboardFactory();
    };

    /* 具体键盘实现 */
    // 华为键盘
    class HuaweiKeyborad : public Keyboard
    {
    public:
        virtual std::string Typewrite() override;
    };

    // 苹果键盘
    class AppleKeyborad : public Keyboard
    {
    public:
        virtual std::string Typewrite() override;
    };

    // 小米键盘
    class XiaomiKeyborad : public Keyboard
    {
    public:
        virtual std::string Typewrite() override;
    };

    /* 具体键盘工厂实现 */
    // 华为键盘工厂
    class HuaweiKeyboardFactory : public KeyboardFactory
    {   
    public:
        virtual Keyboard* GetKeyborad() override;
    };

    // 苹果键盘工厂
    class AppleKeyboardFactory : public KeyboardFactory
    {   
    public:
        virtual Keyboard* GetKeyborad() override;
    };

    // 小米键盘工厂
    class XiaomiKeyboardFactory : public KeyboardFactory
    {   
    public:
        virtual Keyboard* GetKeyborad() override;
    };

}



#endif