#include "StateMachine.h"

StateMachine::StateMachine(
    TrafficLights& lights,
    TimerManager& timer)
    :
    trafficLights(lights),
    timer(timer)
{

}

void StateMachine::begin()
{
    currentState = TrafficState::INIT;

    pendingCommand.valid = false;

    enterMainGreen();
}

void StateMachine::handleCommand(const Command& command)
{
    if (!command.valid)
        return;

    pendingCommand = command;

    hasPendingCommand = true;
}

void StateMachine::update()
{
    if (!timer.expired())
        return;

    switch (currentState)
    {
        case TrafficState::MAIN_GREEN:

            transitionFromMain = true;

            enterMainYellow();

            break;

        case TrafficState::MAIN_YELLOW:

            enterAllRedToSide();

            break;

        case TrafficState::ALL_RED_TO_SIDE:

            enterSideGreen();

            break;

        case TrafficState::SIDE_GREEN:

            transitionFromMain = false;

            enterSideYellow();

            break;

        case TrafficState::SIDE_YELLOW:

            enterAllRedToMain();

            break;

        case TrafficState::ALL_RED_TO_MAIN:

            enterMainGreen();

            break;

        default:

            break;
    }
}

void StateMachine::enterMainGreen()
{
    currentState = TrafficState::MAIN_GREEN;

    trafficLights.setMainGreen();

    currentGreenDuration = 10000;

    if (hasPendingCommand &&
        pendingCommand.type == CommandType::REQUEST_MAIN)
    {
        currentGreenDuration = pendingCommand.duration * 1000;

        hasPendingCommand = false;
        pendingCommand.valid = false;
    }

    timer.start(currentGreenDuration);
}

void StateMachine::enterMainYellow()
{
    currentState = TrafficState::MAIN_YELLOW;

    trafficLights.setMainYellow();

    timer.start(3000);
}

void StateMachine::enterAllRedToSide()
{
    currentState = TrafficState::ALL_RED_TO_SIDE;

    trafficLights.setAllRed();

    timer.start(1000);
}

void StateMachine::enterSideGreen()
{
    currentState = TrafficState::SIDE_GREEN;

    trafficLights.setSideGreen();

    currentGreenDuration = 10000;

    if (hasPendingCommand &&
        pendingCommand.type == CommandType::REQUEST_SIDE)
    {
        currentGreenDuration = pendingCommand.duration * 1000;

        hasPendingCommand = false;
        pendingCommand.valid = false;
    }

    timer.start(currentGreenDuration);
}

void StateMachine::enterSideYellow()
{
    currentState = TrafficState::SIDE_YELLOW;

    trafficLights.setSideYellow();

    timer.start(3000);
}

void StateMachine::enterAllRedToMain()
{
    currentState = TrafficState::ALL_RED_TO_MAIN;

    trafficLights.setAllRed();

    timer.start(1000);
}

TrafficState StateMachine::getCurrentState() const
{
    return currentState;
}