#ifndef TRAFFIC_LIGHTS_H
#define TRAFFIC_LIGHTS_H

#include <Arduino.h>

class TrafficLights
{
public:

    // Initialize all GPIO pins
    void begin();

    // Main Road
    void setMainGreen();
    void setMainYellow();
    void setMainRed();

    // Side Road
    void setSideGreen();
    void setSideYellow();
    void setSideRed();

    // Safety
    void setAllRed();

    // Turn everything off
    void allOff();

private:

    // Helper function
    void turnOffAll();
};

#endif