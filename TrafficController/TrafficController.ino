#include "Config.h"

#include "TrafficLights.h"
#include "TimerManager.h"
#include "SerialManager.h"
#include "CommandParser.h"
#include "StateMachine.h"

TrafficLights trafficLights;
TimerManager timer;
SerialManager serialManager;
CommandParser parser;

StateMachine stateMachine(trafficLights, timer);

void setup()
{
    trafficLights.begin();

    serialManager.begin(SERIAL_BAUD_RATE);

    stateMachine.begin();

    serialManager.sendMessage("Smart Traffic Controller Ready");
}

void loop()
{
    // Read serial data
    serialManager.update();

    // Process new command
    if (serialManager.available())
{
    Serial.println("Message Received!");

    String msg = serialManager.getMessage();

    Serial.print("Raw Message: ");
    Serial.println(msg);

    // changed here 
Command cmd = parser.parse(msg);

if (cmd.valid)
{
    Serial.println("VALID COMMAND");
    Serial.print("Duration = ");
    Serial.println(cmd.duration);
}
else
{
    Serial.println("INVALID COMMAND");
}

stateMachine.handleCommand(cmd);
    //change end here

    serialManager.clearMessage();
}

    // Update controller
    stateMachine.update();
}