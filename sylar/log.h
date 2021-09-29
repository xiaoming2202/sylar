#ifndef _SYLAR_LOG_H_
#define _SYLAR_LOG_H_

#include <string>
#include <stdint.h>
#include <memory>

namespace sylar
{

    class LogEvent
    {
    public:
        typedef std::shared_ptr<LogEvent> ptr;
        LogEvent();

    private:
        const char *m_file = nullptr;//文件名
        int32_t m_line = 0;//行号
        uint32_t m_threadId = 0;//线程id
        uint32_t m_fiberId = 0;//协程id
        uint64_t m_time;//时间戳
        std::string m_content;
    };
    

    //日志级别
    class LogLevel{
        public:
                enum Level{
            DEBUG=1,
            INFO=2,
            WARN=3,
            ERROR=4,
            FATAL=5
        };
    };

    
    //日志格式器
    class LogFormatter{
        public:
        typedef std::shared_ptr<LogFormatter> ptr;
        str::string format(LogEvent::ptr event);
        private:
    };




    //日志输出地
    class LogAppender{
        public:
        typedef std::shared_ptr<LogAppender> ptr;
        virtual ~LogAppender();
        void log(LogLevel::Level level, LogEvent::ptr event);
        private:
        LogLevel::Level m_level;
    };



    //日志器
    class Logger{
        public:
        typedef std::shared_ptr<Logger> ptr;
        Logger(const std::string& name="root");
        void log(LogLevel:: Level level,const LogEvent& event);
        private:
        std::string m_name;
        LogAppender::ptr
    };

//输出到控制台的Appender
class StdoutLogAppender : public LogAppender{

};

//定义到输出文件的Appender
class FileLogAppender : public LogAppender{

};



}
#endif
