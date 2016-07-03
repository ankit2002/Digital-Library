#ifndef SYNCTCPCLIENT_H
#define SYNCTCPCLIENT_H
#include <string.h>
#include <boost/asio.hpp>
#include <iostream>
#include <sstream>
#include <map>


class SyncTCPClient
{
public:
    SyncTCPClient(const std::string& raw_ip_address, unsigned short port_num);

    void connect();

    void close();

    std::string emulateLongComputationOp(
    unsigned int duration_sec,std::string jsonToSend);
protected:
private:
    void sendRequest(const std::string& request);
    std::string receiveResponse();
    boost::asio::io_service m_ios;
    boost::asio::ip::tcp::endpoint m_ep;
    boost::asio::ip::tcp::socket m_sock;
};

#endif // SYNCTCPCLIENT_H
