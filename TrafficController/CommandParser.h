#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <Arduino.h>
#include "Protocol.h"

class CommandParser
{
public:
    Command parse(const String& message);

private:
    CommandType getCommandType(const String& command);
};

#endif