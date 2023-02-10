#ifndef __ABSTRACT_H__
#define __ABSTRACT_H__
#include "KeyboradFactory.h"
#include "ProcessorFactory.h"
#include "ScreenFactory.h"
#include <string>


namespace ComputerMaking
{
    /* 电脑品牌 */
    enum Brand { HUAWEI = 0, APPLE, XIAOMI };

    /* 电脑类 */
    class Computer
    {
    public:
        Computer(Brand brand, Processor* processor, Screen* screen, Keyboard* keyboard);
        ~Computer();
        Computer(const Computer&) = delete;
        Computer& operator = (const Computer&) = delete;
        // 电脑的功能 ...
    
    private:
        Brand _brand;
        Processor* _processor;
        Screen* _screen;
        Keyboard* _keyborad;
    };


    /* 工厂的基类 */
    class ComputerFactory
    {
    public:
        // 构造与析构
        ComputerFactory(Brand brand, ProcessorFactory* processorFactory, ScreenFactory* screenFactory, KeyboardFactory* keyboardFactory);
        ~ComputerFactory();  
        // 获得电脑
        Computer* GetComputer() const;
        // getter
        Brand GetBrand() const;
    private:
        // 释放资源
        void DeleteFactorySource();
        // 检查工厂是否合法
        bool IsFactoryCanWork() const;

        // 其中有三个工厂
        Brand _brand;
        ProcessorFactory* _processorFactory;
        ScreenFactory* _screenFactory;
        KeyboardFactory* _keyboardFactory;
    };

    class HuaweiComputerFactory : public ComputerFactory
    {
    public:
        HuaweiComputerFactory();
    };

    class AppleComputerFactory : public ComputerFactory
    {
    public:
        AppleComputerFactory();
    };

    class XiaomiComputerFactory : public ComputerFactory
    {
    public:
        XiaomiComputerFactory();
    };

}


#endif