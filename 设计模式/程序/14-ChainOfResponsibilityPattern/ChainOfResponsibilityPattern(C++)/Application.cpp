/* C++ 实现责任链模式 */
#include <iostream>
#include <string>


namespace ChainOfResponsibilityPattern
{
    /* 日志类型枚举 */
    enum LogType { CONCOLE_LOG = 0, ERROR_LOG, FILE_LOG, OTHER_LOG};
    
    /* 日志基类 */
    class Logger
    {
    public:
        // 构造
        Logger(): _nextLogerr(nullptr) 
        {  }
        virtual ~Logger(){}
        // 做日志
        void LogMessage(LogType logType, const std::string& message)
        {
            if (CanLogMessage(logType))
                // 可以做日志
                this->WriteMessage(message);
            // 不能就交给下一个处理
            else
            { 
                if (this->_nextLogerr == nullptr)
                    // 已经到了链表尾，无法处理！
                    std::cout << "No Logger can handle this logging task!" << std::endl;
                else
                    this->_nextLogerr->LogMessage(logType, message);
            }
        }
        // 设置下一个日志者
        void SetNextLogger(Logger* nextLogger)
        {
            this->_nextLogerr = nextLogger;
        }

    protected:
        // 判断是否可以处理
        virtual bool CanLogMessage(LogType logType) = 0;
        // 打印日志
        virtual void WriteMessage(const std::string& message) = 0;

        // 一个指向下一个 Logger 的指针，形成链表
        Logger* _nextLogerr;
    };

    /* 具体的日志记录类 */
    class ConsoleLogger : public Logger
    {
    public:
        ConsoleLogger() : Logger() {}
    protected:
        virtual bool CanLogMessage(LogType logType) override
        {
            return logType == LogType::CONCOLE_LOG;
        }
        // 打印日志
        virtual void WriteMessage(const std::string& message) override
        {
            std::cout << "Console Log: " << message << std::endl;
        }
    };   
    
    class ErrorLogger : public Logger
    {
    public:
        ErrorLogger() : Logger() {}
    protected:
        virtual bool CanLogMessage(LogType logType) override
        {
            return logType == LogType::ERROR_LOG;
        }
        // 打印日志
        virtual void WriteMessage(const std::string& message) override
        {
            std::cout << "Error Log: " << message << std::endl;
        }
    };

    class FileLogger : public Logger
    {
    public:
        FileLogger() : Logger() {}
    protected:
        virtual bool CanLogMessage(LogType logType) override
        {
            return logType == LogType::FILE_LOG;
        }
        // 打印日志
        virtual void WriteMessage(const std::string& message) override
        {
            std::cout << "File Log: " << message << std::endl;
        }
    };
}

int main()
{
    using namespace ChainOfResponsibilityPattern;
    // 创建日志者
    Logger* consoleLogger = new ConsoleLogger();
    Logger* errorLogger = new ErrorLogger();
    Logger* fileLogger = new FileLogger(); 

    // 创建责任链
    consoleLogger->SetNextLogger(errorLogger);
    errorLogger->SetNextLogger(fileLogger);

    // 发布任务
    Logger* handLogger = consoleLogger;
    handLogger->LogMessage(LogType::ERROR_LOG, "New Space Fail!");
    handLogger->LogMessage(LogType::CONCOLE_LOG, "Hello World!");
    handLogger->LogMessage(LogType::FILE_LOG, "Today is a sunny day!");
    handLogger->LogMessage(LogType::OTHER_LOG, "NONONONONON");

    delete consoleLogger;
    delete errorLogger;
    delete fileLogger;
    return 0;
}