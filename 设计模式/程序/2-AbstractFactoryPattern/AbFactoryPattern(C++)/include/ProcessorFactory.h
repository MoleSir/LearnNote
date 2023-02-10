#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__
#include <string>


namespace ComputerMaking
{
    /* 处理器基类 */
    class Processor
    {
    public:
        virtual bool ProcessTask(const std::string& task) = 0;
        virtual ~Processor();
    };

    /* 处理器工厂 */
    class ProcessorFactory
    {
    public:
        virtual Processor* GetProcessor() = 0;
        virtual ~ProcessorFactory();
    };

    /* 处理器实现类 */
    class HuaweiProcessor : public Processor
    {
    public:
        virtual bool ProcessTask(const std::string& task) override;
    };

    class AppleProcessor : public Processor
    {
    public:
        virtual bool ProcessTask(const std::string& task) override;
    };

    class XiaomiProcessor : public Processor
    {
    public:
        virtual bool ProcessTask(const std::string& task) override;
    };

    /* 处理器工厂实现类 */
    class HuaweiProcessorFactory : public ProcessorFactory
    {
    public:
        virtual Processor* GetProcessor() override;
    };

    class AppleProcessorFactory : public ProcessorFactory
    {
    public:
        virtual Processor* GetProcessor() override;
    };

    class XiaomiProcessorFactory : public ProcessorFactory
    {
    public:
        virtual Processor* GetProcessor() override;
    };
}


#endif