/**
 * @file Log.h
 * @author li yingtai (626145245@.com)
 * @brief Log
 * @version 0.1
 * @date 2024-01-14
 *
 * @copyright Copyright (c) 2024
 *
 */


 //----------------log module not thread safe

#include<string>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<map>
#include"LogMacro.h"

//------------------------------------------Log Base----------------------------
#define LOG(LEVEL,...)  \
        Log::GetLogSingle(LEVEL)->GetLogStream() <<__DATE__ << " "<< __TIME__ <<" " << __FILE__ << " "<< __FUNCTION__ <<" ["<< __LINE__<< "] " <<__VA_ARGS__; \
        Log:: GetLogSingle()->OutPutLog();


#define LOG_DEBUG(...) \
        LOG(LogLevel::DEBUG,__VA_ARGS__)

#define LOG_TRACE(...) \
        LOG(LogLevel::TRACE,__VA_ARGS__)

#define LOG_INFO(...) \
        LOG(LogLevel::INFO,__VA_ARGS__)

#define LOG_ERROR(...) \
        LOG(LogLevel::ERROR,__VA_ARGS__)

#define LOG_WARN(...) \
        LOG(LogLevel::WARN,__VA_ARGS__)

class Log {

private:
    Log(const LogLevel level, LogOutMode logmode);
    Log();
    Log(const Log&) = delete;

public:
    static Log* GetLogSingle(const LogLevel level, LogOutMode logmode = LogOutMode::TERMINAL);
    static Log* GetLogSingle();
    std::stringstream& GetLogStream();
    ~Log();
public:

    //set Log parameter
    void SetLogOutMode(const LogOutMode logmode);
    void SetLogLevel(const LogLevel level);
    int SetLogFile(const std::string& Logfile);

    //outPut log target
    virtual int OutPutLogToTerminal();
    virtual int OutPutLogToWidget();
    virtual int OutPutLogToFIle();
    int OutPutLog();

private:
    std::map<LogLevel, std::string> m_mapModeToString{ {LogLevel::DEBUG,"[DEBUG]"},{LogLevel::ERROR,"[ERROR]"},{LogLevel::WARN,"[WARN]"},
                                                       {LogLevel::TRACE,"TRACE"},{LogLevel::INFO,"[INFO]"}
    };

private:
    std::stringstream m_logStream;
    std::fstream     m_fileStream;
    LogOutMode m_outMode{ LogOutMode::FILE };
    LogLevel   m_level{ LogLevel::DEBUG };
    std::string m_file{ "" };
    static Log* m_singleLog;
};

