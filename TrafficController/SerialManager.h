#ifndef SERIAL_MANAGER_H
#define SERIAL_MANAGER_H

#include <Arduino.h>

class SerialManager
{
public:
    void begin(unsigned long baudRate);

    void update();

    bool available();

    String getMessage();

    void clearMessage();

    void sendMessage(const String &message);

private:
    String rxBuffer = "";
    String message = "";
    bool newMessage = false;
};

#endif