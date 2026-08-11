#ifndef TIMER_MANAGER_H
#define TIMER_MANAGER_H

#include <Arduino.h>

class TimerManager
{
public:

    void start(unsigned long duration);

    void stop();

    bool expired();

    bool running();

    unsigned long elapsed();

    unsigned long remaining();

private:

    unsigned long startTime = 0;

    unsigned long duration = 0;

    bool active = false;
};

#endif