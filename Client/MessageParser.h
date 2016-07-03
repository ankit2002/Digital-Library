#ifndef MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include "NetworkMessage.h"
#include "PureMessage.h"

class MessageParser
{
public:
    MessageParser();
    virtual ~MessageParser();
    NetworkMessage* CreateMessage(Commands, PureMessage*)
    {

    }

    PureMessage* Message(char[])
    {


    }
protected:
private:
};

#endif // MESSAGEPARSER_H
