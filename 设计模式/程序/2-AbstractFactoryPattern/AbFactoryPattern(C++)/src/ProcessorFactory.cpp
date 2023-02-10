#include "ProcessorFactory.h"
#include <string>
#include <iostream>


namespace ComputerMaking
{
    Processor::~Processor()
    {}

    bool HuaweiProcessor::ProcessTask(const std::string& task)
    {
        std::cout << "Huawei Processor Processes the Task: " << task << std::endl;
        return true;
    }

    bool AppleProcessor::ProcessTask(const std::string& task)
    {
        std::cout << "Apple Processor Processes the Task: " << task << std::endl;
        return true;
    }

    bool XiaomiProcessor::ProcessTask(const std::string& task)
    {
        std::cout << "Xiaomi Processor Processes the Task: " << task << std::endl;
        return true;
    }


    ProcessorFactory::~ProcessorFactory()
    {}

    Processor* HuaweiProcessorFactory::GetProcessor()
    {
        return new HuaweiProcessor();
    }

    Processor* AppleProcessorFactory::GetProcessor()
    {
        return new AppleProcessor();
    }

    Processor* XiaomiProcessorFactory::GetProcessor()
    {
        return new XiaomiProcessor();
    }
}