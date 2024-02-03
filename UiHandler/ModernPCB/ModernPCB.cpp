/*****************************************************************//**
 * \file   LogTest.cpp
 * \brief  
 * 
 * \author liyingtai
 * \date   January 2024
 *********************************************************************/

#include <QApplication>
#include "Log.h"
#include"Mainwindow/MPMainwindow.h"
int main(int argc,char*argv[])
{
    QApplication app(argc, argv);
    auto log = Log::GetLogSingle();
    log->SetLogFile("./log.txt");
    LOG_DEBUG("okokokok");
    //log->SetLogOutMode(LogOutMode::TERMINAL);
    LOG_DEBUG("liyingtai");
    MPMainwindow a;
    a.show();
    return app.exec();
}