#include "logger.hpp"

Logger* Logger::m_logger = nullptr;

Logger::Logger()
    :m_logLevel(LogLevel::INFO)
{
}

Logger::~Logger()
{
}

Logger* Logger::getLogger()
{
    if (nullptr == m_logger) {
        m_logger = new Logger();
    }

    return m_logger;
}

bool Logger::setLogLevel(LogLevel level)
{
    if (LogLevel::DEBUG < level) {
        return false;
    }

    m_logLevel = level;

    return true;
}

void Logger::printLog(LogLevel level, const char* fmt, ...)
{
    va_list args;
    Logger* logger = getLogger();

    if (level <= logger->m_logLevel) {
        va_start(args, fmt);
        vprintf(fmt, args);
        va_end(args);
    }

}
