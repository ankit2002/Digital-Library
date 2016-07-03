#ifndef NETWORKSETTINGS_H
#define NETWORKSETTINGS_H

#include <boost/array.hpp>
#include "iostream"

class NetworkSettings
{
public:
    NetworkSettings();
    virtual ~NetworkSettings();
    std::string  destinationIp = "127.0.0.1";
    int destinationPort=8000;


    std::string getIp()
    {
        return destinationIp;
    }


    int getPort()
    {
        return destinationPort;
    }

    void readSettings()
    {

    }
protected:
private:
};

#endif // NETWORKSETTINGS_H
