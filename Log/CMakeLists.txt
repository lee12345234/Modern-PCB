message("LogTest---${PROJECT_SOURCE_DIR}")
set(LogSource ./Log/Log.cpp)
set(LogDirectory ./Log/Log.h 
              ./Log/LogMacro.h)
aux_source_directory(. DIR_SRCS)
add_executable(LogTest LogTest.cpp) 