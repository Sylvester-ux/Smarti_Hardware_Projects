#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <Arduino.h>

#include "Protocol.h"
#include "TrafficLights.h"
#include "TimerManager.h"

class StateMachine
{
public:

    StateMachine(
        TrafficLights& lights,
        TimerManager& timer);

    void begin();

    void update();

    void handleCommand(const Command& command);

    TrafficState getCurrentState() const;

private:

    TrafficLights& trafficLights;

    TimerManager& timer;

    TrafficState currentState;

    Command pendingCommand;

    bool hasPendingCommand = false;

    uint16_t currentGreenDuration = 10000;

    bool transitionFromMain = true;

    void enterMainGreen();

    void enterMainYellow();

    void enterAllRedToSide();

    void enterSideGreen();

    void enterSideYellow();

    void enterAllRedToMain();
};

#endif