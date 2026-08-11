#include "TrafficLights.h"
#include "Config.h"

void TrafficLights::begin()
{
    pinMode(MAIN_RED_PIN, OUTPUT);
    pinMode(MAIN_YELLOW_PIN, OUTPUT);
    pinMode(MAIN_GREEN_PIN, OUTPUT);

    pinMode(SIDE_RED_PIN, OUTPUT);
    pinMode(SIDE_YELLOW_PIN, OUTPUT);
    pinMode(SIDE_GREEN_PIN, OUTPUT);

    setAllRed();
}

void TrafficLights::turnOffAll()
{
    digitalWrite(MAIN_RED_PIN, LOW);
    digitalWrite(MAIN_YELLOW_PIN, LOW);
    digitalWrite(MAIN_GREEN_PIN, LOW);

    digitalWrite(SIDE_RED_PIN, LOW);
    digitalWrite(SIDE_YELLOW_PIN, LOW);
    digitalWrite(SIDE_GREEN_PIN, LOW);
}

void TrafficLights::setMainGreen()
{
    turnOffAll();

    digitalWrite(MAIN_GREEN_PIN, HIGH);
    digitalWrite(SIDE_RED_PIN, HIGH);
}

void TrafficLights::setMainYellow()
{
    turnOffAll();

    digitalWrite(MAIN_YELLOW_PIN, HIGH);
    digitalWrite(SIDE_RED_PIN, HIGH);
}

void TrafficLights::setMainRed()
{
    turnOffAll();

    digitalWrite(MAIN_RED_PIN, HIGH);
}

void TrafficLights::setSideGreen()
{
    turnOffAll();

    digitalWrite(SIDE_GREEN_PIN, HIGH);
    digitalWrite(MAIN_RED_PIN, HIGH);
}

void TrafficLights::setSideYellow()
{
    turnOffAll();

    digitalWrite(SIDE_YELLOW_PIN, HIGH);
    digitalWrite(MAIN_RED_PIN, HIGH);
}

void TrafficLights::setSideRed()
{
    turnOffAll();

    digitalWrite(SIDE_RED_PIN, HIGH);
}

void TrafficLights::setAllRed()
{
    turnOffAll();

    digitalWrite(MAIN_RED_PIN, HIGH);
    digitalWrite(SIDE_RED_PIN, HIGH);
}

void TrafficLights::allOff()
{
    turnOffAll();
}