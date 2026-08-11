#ifndef SYSTEM_STATUS_H
#define SYSTEM_STATUS_H

#include <Arduino.h>

/*************************************************
 *          TRAFFIC LIGHT STATES
 *************************************************/

enum class TrafficState
{
    INIT,               // System startup

    MAIN_GREEN,
    MAIN_YELLOW,

    ALL_RED,

    SIDE_GREEN,
    SIDE_YELLOW,

    EMERGENCY_MAIN,
    EMERGENCY_SIDE,

    FAILSAFE
};


/*************************************************
 *          SYSTEM MODES
 *************************************************/

enum class SystemMode
{
    NORMAL,

    EMERGENCY,

    FAILSAFE
};


/*************************************************
 *          SYSTEM STATUS STRUCTURE
 *************************************************/

struct SystemStatus
{
    TrafficState currentState = TrafficState::INIT;

    TrafficState previousState = TrafficState::INIT;

    SystemMode mode = SystemMode::NORMAL;

    unsigned long stateStartTime = 0;

    unsigned long stateDuration = 0;

    bool communicationAlive = true;

    bool emergencyActive = false;
};

#endif