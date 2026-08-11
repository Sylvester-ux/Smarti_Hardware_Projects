#include "CommandParser.h"

Command CommandParser::parse(const String& message)
{
    Command cmd;

    int commaIndex = message.indexOf(',');

    String commandString;
    String durationString;

    if (commaIndex == -1)
    {
        commandString = message;
    }
    else
    {
        commandString = message.substring(0, commaIndex);
        durationString = message.substring(commaIndex + 1);
    }

    commandString.trim();
    durationString.trim();

    cmd.type = getCommandType(commandString);

    if (durationString.length() > 0)
    {
        cmd.duration = durationString.toInt();
    }
    else
    {
        cmd.duration = 0;
    }

    cmd.valid = (cmd.type != CommandType::NONE);

    return cmd;
}

CommandType CommandParser::getCommandType(const String& command)
{
    if (command == "REQUEST_MAIN")
        return CommandType::REQUEST_MAIN;

    if (command == "REQUEST_SIDE")
        return CommandType::REQUEST_SIDE;

    if (command == "EMERGENCY_MAIN")
        return CommandType::EMERGENCY_MAIN;

    if (command == "EMERGENCY_SIDE")
        return CommandType::EMERGENCY_SIDE;

    if (command == "STATUS")
        return CommandType::STATUS_REQUEST;

    if (command == "RESET")
        return CommandType::RESET;

    if (command == "FAILSAFE")
        return CommandType::FAILSAFE;

    return CommandType::NONE;
}