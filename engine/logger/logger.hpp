#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#ifndef __FUNCTION_NAME__
    #ifdef WIN32   //WINDOWS
        #define __FUNCTION_NAME__   __FUNCTION__  
    #else          //*NIX
        #define __FUNCTION_NAME__   __func__ 
    #endif
#endif

#include <stdarg.h>
#include <stdio.h>

enum class LogLevel {
    ERROR = 0,
    INFO,
    WARNING,
    DEBUG
};

#define LOG_INFO(fmt, ...)      \
    Logger::printLog(LogLevel::INFO, "%s(%s): [INFO]: " fmt, __FILE__, __FUNCTION_NAME__, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...)     \
    Logger::printLog(LogLevel::DEBUG, "%s(%s): [DEBUG]: " fmt, __FILE__, __FUNCTION_NAME__, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...)     \
    Logger::printLog(LogLevel::ERROR, "%s(%s): [ERROR]: " fmt, __FILE__, __FUNCTION_NAME__, ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...)   \
    Logger::printLog(LogLevel::WARNING, "%s(%s): [WARNING]: " fmt, __FILE__, __FUNCTION_NAME__, ##__VA_ARGS__)

class Logger {
public:
    static Logger* getLogger();

    bool setLogLevel(LogLevel level);
    static void printLog(LogLevel level, const char* fmt, ...);

protected:
    Logger();
    ~Logger();

private:
    static Logger* m_logger;
    LogLevel m_logLevel;
};

#endif /* __LOGGER_HPP__ */
