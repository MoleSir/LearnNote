/* C# 实现责任链模式 */
using System;

namespace ChainOfResponsibilityPattern
{
    /* 枚举 */
    public enum LogType { CONCOLE_LOG, ERROR_LOG, FILE_LOG, OTHER_LOG };

    /* 抽象基类 */
    public abstract class Logger
    {
        public Logger() 
        {
            this.nextLogger = null;
        }
        public void LogMessage(LogType logType, string message)
        {
            if (this.CanLogMessage(logType) == true)
                this.WriteMessage(message);
            else
            {
                if (this.nextLogger == null) 
                    Console.WriteLine("No Logger can handle this logging task!");
                else
                    this.nextLogger.LogMessage(logType, message);
            }
        }
        public void SetNextLogger(Logger nextLogger)
        {
            this.nextLogger = nextLogger;
        }

        protected abstract bool CanLogMessage(LogType logType);
        protected abstract void WriteMessage(string message);
        private Logger nextLogger;
    }

    /* 具体的日治者 */
    class ConsoleLogger : Logger
    {   
        public ConsoleLogger() : base() {}
        protected override bool CanLogMessage(LogType logType)
        {
            return logType == LogType.CONCOLE_LOG;
        }
        protected override void WriteMessage(string message)
        {
            Console.WriteLine("Console Log: {0}", message);
        }
    }

    class ErrorLogger : Logger
    {   
        public ErrorLogger() : base() {}
        protected override bool CanLogMessage(LogType logType)
        {
            return logType == LogType.ERROR_LOG;
        }
        protected override void WriteMessage(string message)
        {
            Console.WriteLine("Error Log: {0}", message);
        }
    }

    class FileLogger : Logger
    {   
        public FileLogger() : base() {}
        protected override bool CanLogMessage(LogType logType)
        {
            return logType == LogType.FILE_LOG;
        }
        protected override void WriteMessage(string message)
        {
            Console.WriteLine("File Log: {0}", message);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Logger consoleLogger = new ConsoleLogger();
            Logger errorLogger = new ErrorLogger();
            Logger fileLogger = new FileLogger();

            consoleLogger.SetNextLogger(errorLogger);
            errorLogger.SetNextLogger(fileLogger);

            Logger handLogger = consoleLogger;
            handLogger.LogMessage(LogType.ERROR_LOG, "New Space Fail!");
            handLogger.LogMessage(LogType.CONCOLE_LOG, "Hello World!");
            handLogger.LogMessage(LogType.FILE_LOG, "Today is a sunny day!");
            handLogger.LogMessage(LogType.OTHER_LOG, "NONONONONON");
        }
    }
}