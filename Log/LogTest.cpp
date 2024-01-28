/*****************************************************************//**
 * \file   LogTest.cpp
 * \brief  
 * 
 * \author liyingtai
 * \date   January 2024
 *********************************************************************/
#include "Log.h"

int main()
{
    LOG_DEBUG("okokokok");
    LOG_DEBUG("haode");
    auto log = Log::GetLogSingle();
    log->SetLogFile("./log.txt");
    LOG_DEBUG("okokokok");
    //log->SetLogOutMode(LogOutMode::TERMINAL);
    LOG_DEBUG("liyingtai");
}