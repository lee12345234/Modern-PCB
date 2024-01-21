#include "Log.h"

Log*Log::m_singleLog = nullptr;

Log::Log(const LogLevel level,LogOutMode logmode = LogOutMode::TERMINAL,std::string file = "")
{
  if(logmode == LogOutMode::FILE && !file.empty())
  {
    setLogFile(file);
  }
  else if(logmode == LogOutMode::FILE && file.empty())
  {
    m_logStream<<"Time:"<<__DATE__<<"  Function:"<<__FUNCTION__<<" LogMode:"<<logmode<<"file:"<<file;

  }
  else if(logmode != LogOutMode::FILE && !file.empty())
  {
    m_logStream<<"Time:"<<__DATE__<<"  Function:"<<__FUNCTION__<<" LogMode:"<<logmode<<"file:"<<file;
  }


  setLogOutMode(logmode);
  setLogLevel(level);

}

//m_single Log couldnt be nullptr in this program
Log*Log::GetLogSingle()
{
  return m_singleLog;
}

Log*Log::GetLogSingle(const LogLevel level,LogOutMode logmode = LogOutMode::TERMINAL,std::string file = "")
{
  if(m_singleLog==nullptr)
  {
    m_singleLog= new Log(level,logmode,file);
  }
  return m_singleLog;
}

void Log::setLogOutMode(const LogOutMode mode)
{
  m_outMode = mode;

}


int Log::setLogFile(const std::string&file)
{

  m_file = file;
  m_fileStream.open("m_file",std::ios::app);
  if(!m_fileStream.is_open())
  {
    #ifdef __WIN32
    #include <windows.h>
      auto Handle = CreateFile(m_file,GENERIC_WRITE | GENERIC_READ,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,NULL);
      if(Handle == INVALID_HANDLE_VALUE)
      {
        m_logStream << "create file failed";
      }
    #elif __linux__
    #include <fcntl.h>
    #include <errno.h>
    #include <string.h>
      auto ret = creat(m_file.c_str(),S_IRUSR | S_IWUSR);
      if(ret < 0)
      {
        m_logStream<< std::string(strerror(errno));
      }
    #endif
  }

}

void Log::setLogLevel(const LogLevel level)
{
  m_level = level;
}

std::stringstream&Log::getLogStream()
{

    return m_logStream;
}
