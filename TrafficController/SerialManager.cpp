#include "SerialManager.h"

void SerialManager::begin(unsigned long baudRate)
{
    Serial.begin(baudRate);

    while (!Serial)
    {
        ;   // Wait for Serial on boards that support it
    }
}

void SerialManager::update()
{
    while (Serial.available())
    {
        char c = Serial.read();

        if (c == '\n')
        {
            message = rxBuffer;
            rxBuffer = "";
            newMessage = true;
        }
        else
        {
            rxBuffer += c;
        }
    }
}

bool SerialManager::available()
{
    return newMessage;
}

String SerialManager::getMessage()
{
    return message;
}

void SerialManager::clearMessage()
{
    message = "";
    newMessage = false;
}

void SerialManager::sendMessage(const String &message)
{
    Serial.println(message);
}