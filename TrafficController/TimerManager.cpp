#include "TimerManager.h"

void TimerManager::start(unsigned long time)
{
    duration = time;
    startTime = millis();
    active = true;
}

void TimerManager::stop()
{
    active = false;
}

bool TimerManager::running()
{
    return active;
}

bool TimerManager::expired()
{
    if (!active)
        return false;

    if (millis() - startTime >= duration)
    {
        active = false;
        return true;
    }

    return false;
}

unsigned long TimerManager::elapsed()
{
    if (!active)
        return 0;

    return millis() - startTime;
}

unsigned long TimerManager::remaining()
{
    if (!active)
        return 0;

    unsigned long passed = millis() - startTime;

    if (passed >= duration)
        return 0;

    return duration - passed;
}