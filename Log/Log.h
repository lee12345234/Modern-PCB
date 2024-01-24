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
#include"LogMacro.h"

//------------------------------------------Log Base----------------------------
#define LOG(DEBUG,...)  \
        GetLogSingle(LogLevel::DEBUG,LogOutMode::WIDGET,std::string(""))->GetLogStream() <<__FILE__<<__FUNCTION__<<__VA_ARGS__ ; \
        GetLogSingle()->OutPutLog();

#define LOG(TRACE,...)  \
        GetLogSingle(LogLevel::TRACE,LogOutMode::WIDGET,std::string(""))->GetLogStream() <<__FILE__<<__FUNCTION__<<__VA_ARGS__ ; \
        GetLogSingle()->OutPutLog();

#define LOG_DEBUG(...) \
        LOG(DEBUG,__VA_ARGS__)

#define LOG_TRACE(...) \
        LOG(TRACE,__VA_ARGS__)

class Log {

private:
    Log(const LogLevel level, LogOutMode logmode, std::string file);
    Log(const Log&) = delete;

public:
    Log* GetLogSingle(const LogLevel level, LogOutMode = LogOutMode::FILE, std::string file = "./CAD/Log.txt");
    Log* GetLogSingle();
    std::stringstream& getLogStream();
    ~Log();
private:

    //set Log parameter
    void setLogOutMode(const LogOutMode logmode);
    void setLogLevel(const LogLevel level);
    int setLogFile(const std::string& Logfile);

    //outPut log target
    virtual int OutPutLogToTerminal();
    virtual int OutPutLogToWidget();
    virtual int OutPutLogToFIle();
    int OutPutLog();

private:
    std::stringstream m_logStream;
    std::ifstream     m_fileStream;
    LogOutMode m_outMode{ LogOutMode::FILE };
    LogLevel   m_level{ LogLevel::DEBUG };
    std::string m_file{ "" };
    static Log* m_singleLog;
};
