#ifndef COMMUNICATIONMANAGER_H
#define COMMUNICATIONMANAGER_H

#include "RequestResult.h"
#include "NetworkMessage.h"
#include "NetworkSettings.h"



class CommunicationManager
{
public:
    CommunicationManager();
    virtual ~CommunicationManager();
    RequestResult sendMessage(NetworkMessage messageToSend);

protected:
private:
    bool isConnected;

    NetworkSettings settings;
};

#endif // COMMUNICATIONMANAGER_H
