#include "AbstractFactory.h"
#include "KeyboradFactory.h"
#include "ProcessorFactory.h"
#include "ScreenFactory.h"
#include <string>
#include <iostream>


namespace ComputerMaking
{
    Computer::Computer(Brand brand, Processor* processor, Screen* screen, Keyboard* keyboard):
        _brand(brand), _processor(processor), _screen(screen), _keyborad(keyboard)
    { }

    Computer::~Computer() 
    {
        if (this->_processor)
        {
            delete this->_processor;
            this->_processor = nullptr;
        }
        if (this->_screen)
        {
            delete this->_screen;
            this->_screen = nullptr;
        }
        if (this->_keyborad)
        {
            delete this->_keyborad;
            this->_keyborad = nullptr;
        }
    }


    ComputerFactory::ComputerFactory(Brand brand, ProcessorFactory* processorFactory, ScreenFactory* screenFactory, KeyboardFactory* keyboardFactory):
        _brand(brand), _processorFactory(processorFactory), _screenFactory(screenFactory), _keyboardFactory(keyboardFactory)
    {}


    void ComputerFactory::DeleteFactorySource()
    {
        if (this->_processorFactory) delete this->_processorFactory;
        if (this->_screenFactory) delete this->_screenFactory;
        if (this->_keyboardFactory) delete this->_keyboardFactory;
    }

    bool ComputerFactory::IsFactoryCanWork() const
    {
        return (this->_processorFactory != nullptr) 
            && (this->_screenFactory != nullptr)
            && (this->_keyboardFactory != nullptr);
    }

    ComputerFactory::~ComputerFactory()
    {
        this->DeleteFactorySource();
    }

    Brand ComputerFactory::GetBrand() const
    {
        return this->_brand;
    }

    Computer* ComputerFactory::GetComputer() const 
    {
        // 检查工厂
        if (this->IsFactoryCanWork() == true) 
        {
            return new Computer(this->_brand,
                                this->_processorFactory->GetProcessor(),
                                this->_screenFactory->GetScreen(),
                                this->_keyboardFactory->GetKeyborad());
        }
        else 
        {
            std::cout << "This is a bad factory" << std::endl;
            return nullptr;
        }
    }


    HuaweiComputerFactory::HuaweiComputerFactory():
        ComputerFactory(HUAWEI, new HuaweiProcessorFactory(), new HuaweiScreenFactory(), new HuaweiKeyboardFactory())
    {}

    AppleComputerFactory::AppleComputerFactory():
        ComputerFactory(APPLE, new AppleProcessorFactory(), new AppleScreenFactory(), new AppleKeyboardFactory())
    {}

    XiaomiComputerFactory::XiaomiComputerFactory():
        ComputerFactory(XIAOMI, new XiaomiProcessorFactory(), new XiaomiScreenFactory(), new XiaomiKeyboardFactory())
    {}
}