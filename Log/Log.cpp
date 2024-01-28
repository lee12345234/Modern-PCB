#include "Log.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#elif _linux
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#endif

Log* Log::m_singleLog = nullptr;
Log::Log(const LogLevel level, LogOutMode logmode = LogOutMode::TERMINAL)
{

    SetLogOutMode(logmode);
    SetLogLevel(level);

}

Log::Log()
{

}

//m_single Log couldnt be nullptr in this program
Log* Log::GetLogSingle()
{
    if (m_singleLog == nullptr)
    {
        m_singleLog = new Log();
    }
    return m_singleLog;
}

Log* Log::GetLogSingle(const LogLevel level, LogOutMode logmode)
{
    if (m_singleLog == nullptr)
    {
        m_singleLog = new Log(level, logmode);
    }
    return m_singleLog;
}

void Log::SetLogOutMode(const LogOutMode mode)
{
    m_outMode = mode;
}


int Log::SetLogFile(const std::string& file)
{

    m_fileStream.open(file, std::ios::app);
    if (!m_fileStream.is_open())
    {

#ifdef _WIN32
        auto  handle = CreateFile(m_file.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
        if (handle == INVALID_HANDLE_VALUE)
        {
            m_logStream << "create file failed";
            return 0;
        }
        


#elif _linux
        auto ret = creat(m_file.c_str(), S_IRUSR | S_IWUSR);
        if (ret < 0)
        {
            m_logStream << std::string(strerror(errno));
            return 0;
        }
#endif
    }

    m_fileStream.close();
    m_file = file;
    SetLogOutMode(LogOutMode::FILE);

    return 1;

}

int Log::OutPutLogToTerminal()
{
    std::cout << m_logStream.str() << std::endl;
    return 1;
}

int Log::OutPutLogToWidget()
{
    return 0;
}

int Log::OutPutLogToFIle()
{
    if (!m_file.empty())
    {
        m_fileStream.open(m_file,std::ios::app);
        m_fileStream << m_logStream.str() << "\n";
        m_fileStream.close();
        return 1;
    }
    return 0;
}

int Log::OutPutLog()
{
    switch (m_outMode)
    {
    case LogOutMode::FILE: {
        return OutPutLogToFIle();
    };
    case LogOutMode::TERMINAL: {
        return OutPutLogToTerminal();
    };
    case LogOutMode::WIDGET: {
        return OutPutLogToWidget();
    };
    };
    return 0;
}

void Log::SetLogLevel(const LogLevel level)
{
    m_level = level;
}

//add lock
std::stringstream& Log::GetLogStream()
{
    m_logStream.str("");
    m_logStream << m_mapModeToString[m_level];
    return m_logStream;
}

Log::~Log()
{
}
