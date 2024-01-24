CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
project(CAD)
set(LogSource Log/Log.cpp
              Log/LogTest.cpp)
set(LogDirectory  Log/Log.h Log/LogMacro.h)

add_executable(CAD  ${LogSource} ${LogDirectory}) 
target_include_directories(CAD 
              PRIVATE 
              ${LogDirectory})

source_group("Log"  FILES Log/Log.cpp  Log/Log.h Log/LogTest.cpp)
source_group("Global_Macro"  FILES Log/LogMacro.h)