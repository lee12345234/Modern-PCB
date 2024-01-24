/*
 * @file LogMacro.h
 * @author li yingtai (626145245@.com)
 * @brief
 * @version 0.1
 * @date 2024-01-14
 *
 * @copyright Copyright (c) 2024
 *
 */
enum class LogLevel {

    TRACE = 1,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL,
    OFF

};
enum class LogOutMode {
    TERMINAL = 1,
    FILE,
    WIDGET
};

