CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(CAD)

set(CMAKE_AUTOMOC ON)
set(LogSource Log/Log.cpp
              Log/LogTest.cpp)
set(LogDirectory  Log/Log.h Log/LogMacro.h)

set(MainwindowSource UiHandler/Mainwindow/MPMainwindow.cpp  UiHandler/Mainwindow/MPMainwindow.h)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
add_executable(CAD  WIN32 ${LogSource} ${LogDirectory} ${MainwindowSource}) 
target_include_directories(CAD 
              PRIVATE 
              Log/)

target_include_directories(CAD
              PRIVATE
              UiHandler/)              
target_link_libraries(CAD  Qt5::Core Qt5::Gui Qt5::Widgets)

source_group("Log"  FILES Log/Log.cpp  Log/Log.h Log/LogTest.cpp)
source_group("Global_Macro"  FILES Log/LogMacro.h)
source_group("Mainwindow" FILES UiHandler/Mainwindow/MPMainwindow.cpp  UiHandler/Mainwindow/MPMainwindow.h)