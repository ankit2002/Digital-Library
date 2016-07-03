#include "CommunicationManager.h"
#include <iostream>
#include <boost/asio.hpp>

#include "PureMessage.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "SyncTCPClient.h"


using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

CommunicationManager::CommunicationManager()
{
    //ctor
}

CommunicationManager::~CommunicationManager()
{
    //dtor
}

RequestResult CommunicationManager::sendMessage(NetworkMessage messageToSend)
{
    RequestResult rr;
    try
    {
        std::string const strMsg=messageToSend.serialize();

        //std::cout<<"Message to send: "<<strMsg;

        //open network connection to the server, send the message and receive the result in JSON format
        //typedef boost::asio::ip::tcp asiotcp;

        boost::asio::io_service io_service;

        std::string address;
        address=settings.getIp();

        SyncTCPClient client(address, settings.getPort());
        client.connect();
        std::string response = client.emulateLongComputationOp(10,strMsg);
        //deserilize the JSON message to an object of type of RequestResult

//        std::cout<<"Server response: "<<response<<std::endl;
        RequestResult reqRes;
        reqRes.deSerialize(response);
//        client.close();
        //std::cout<<response<<std::endl;
//
        return reqRes;


    }
    catch(std::exception const &ex)
    {
      //  std::cout<<ex.what()<<" ";
    }

    return rr;
}
