CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(ModernPCB)

set(CMAKE_AUTOMOC ON)
set(LogSource Log/Log.cpp)
set(LogDirectory  Log/Log.h Log/LogMacro.h)

set(MainwindowSource UiHandler/Mainwindow/MPMainwindow.cpp  UiHandler/Mainwindow/MPMainwindow.h)
set(ModernPCBSource UiHandler/ModernPCB/ModernPCB.cpp)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
add_executable(ModernPCB  WIN32 ${LogSource} ${LogDirectory} ${MainwindowSource} ${ModernPCBSource} ${MenuSource}) 
target_include_directories(ModernPCB 
              PRIVATE 
              Log/)

target_include_directories(ModernPCB
              PRIVATE
              UiHandler/)        

include_directories(${Qt5Widgets_INCLUDE_DIRS})

message(status ${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(ModernPCB  Qt5::Core Qt5::Gui Qt5::Widgets)

source_group(Log  FILES Log/Log.cpp  Log/Log.h)
source_group(Global_Macro  FILES Log/LogMacro.h)
source_group(UiHandler)
source_group(UiHandler/Mainwindow FILES UiHandler/Mainwindow/MPMainwindow.cpp  UiHandler/Mainwindow/MPMainwindow.h)
source_group(ModernPcb FILES UiHandler/ModernPCB/ModernPCB.cpp)