#include "SyncTCPClient.h"
#include <boost/asio.hpp>
#include <iostream>
#include <sstream>
#include <map>

using namespace boost;

SyncTCPClient::SyncTCPClient(const std::string& raw_ip_address, unsigned short port_num) :
    m_ep(boost::asio::ip::address::from_string(raw_ip_address), port_num), m_sock(m_ios)
{
    m_sock.open(m_ep.protocol());
}


void SyncTCPClient::connect()
{
    try
    {
        std::cout<<" Trying to connect to server... "<<std::endl;
        m_sock.connect(m_ep);
        std::cout<<" Connection stablished"<<std::endl;
    }
    /*   catch(system::system_error &e)
       {
           std::cout << "Error occured! in client main Error code = " << e.code() << ". Message: " << e.what();

       }*/
    catch(std::exception const &ex)
    {
        std::cout<<ex.what()<<" ";
    }

}

void SyncTCPClient::close()
{
    m_sock.shutdown(
        boost::asio::ip::tcp::socket::shutdown_both);
    m_sock.close();
}

std::string SyncTCPClient::emulateLongComputationOp(
    unsigned int duration_sec,std::string jsonToSend)
{

    std::string json = "";

    std::string request = jsonToSend + "\n";
    //std::cout<<"request "<<request<<std::endl;
    sendRequest(request);
    return receiveResponse();
};

void SyncTCPClient::sendRequest(const std::string& request)
{
    boost::asio::write(m_sock, boost::asio::buffer(request));
}
std::string SyncTCPClient::receiveResponse()
{
    boost::asio::streambuf buf;
    boost::asio::read_until(m_sock, buf, '\n');

    std::istream input(&buf);
    std::string response;
    std::getline(input, response);

    return response;
}
