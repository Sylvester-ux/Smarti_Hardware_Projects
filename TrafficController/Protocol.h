#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <Arduino.h>

enum class CommandType
{
    NONE,

    REQUEST_MAIN,
    REQUEST_SIDE,

    EMERGENCY_MAIN,
    EMERGENCY_SIDE,

    STATUS_REQUEST,

    RESET,

    FAILSAFE
};

enum class TrafficState
{
    INIT,

    MAIN_GREEN,
    MAIN_YELLOW,

    ALL_RED_TO_SIDE,

    SIDE_GREEN,
    SIDE_YELLOW,

    ALL_RED_TO_MAIN,

    FAILSAFE
};

struct Command
{
    CommandType type;

    uint16_t duration;

    bool valid;
};

#endif