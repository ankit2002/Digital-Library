#ifndef MEMBER_H
#define MEMBER_H

#include "PureMessage.h"
#include <iostream>
#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

class Member : PureMessage
{
public:
    Member();
    virtual ~Member();
    virtual std::string serialize();
    std::string serialize(std::map<int, Member> memberData);

    // Setter Method
    void setMemberId(int mid);
    void setAddress(std::string add);
    void setEmailAddress(std::string emailAdd);
    void setName(std::string nameObj);
    void setRegistrationDate(std::string registrationDateStr);

    // Getter Method
    int getMemberId();
    std::string getAddress();
    std::string getEmailAddress();
    std::string getName();
    std::string getRegistrationDate();

    // Deserialize
    void deSerialize(std::string ntwMsg);

    void print();
protected:
private:
    std::string address;
    std::string emailAddress;
    std::string name;
    std::string registerationDate;
    int memberId;
};

#endif // MEMBER_H
