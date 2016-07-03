//
// Created by Ankit Mishra on 19/06/16.
//

#ifndef SERVER_NETWORKSETTING_H
#define SERVER_NETWORKSETTING_H

#include <iostream>

using namespace std;

class NetworkSetting {

public:
//    std::string getIP();
    int getPort();

private:
//    std::string destinationIP = "127.0.0.1";
    int destinationPort = 8000;
};


#endif //SERVER_NETWORKSETTING_H
