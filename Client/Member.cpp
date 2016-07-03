#include "Member.h"

Member::Member()
{
    //ctor
}

Member::~Member()
{
    //dtor
}


int Member::getMemberId()
{
    return memberId;
}
void Member::setMemberId(int mid)
{
    if(mid>0)
    {
        memberId=mid;
    }
}
std::string Member::getAddress()
{
    return address;
}
void Member::setAddress(std::string add)
{
    address=add;
}

std::string Member::getEmailAddress()
{
    return emailAddress;
}

void Member::setEmailAddress(std::string emailAdd)
{
    emailAddress = emailAdd;
}

std::string Member::getName()
{
    return name;
}

void Member::setName(std::string nameStr)
{
    name = nameStr;
}

std::string Member::getRegistrationDate()
{
    return registerationDate;
}

void Member::setRegistrationDate(std::string registrationDateStr)
{
    registerationDate = registrationDateStr;
}


std::string Member::serialize()
{
    std::string serializedMember;

    ptree pt;

    pt.put ("memberId",std::to_string(Member::memberId));
    std::string strAddress(Member::address);
    pt.put ("address", strAddress);
    std::string strEmail(Member::emailAddress);
    pt.put ("emailAddress", strEmail);
    std::string strName(Member::name);
    pt.put ("name", strName);
    std::string strRegDate(Member::name);
    pt.put ("registerationDate", strRegDate);

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedMember = buf.str();


    return serializedMember;
}


void Member::deSerialize(std::string ntwMsg)
{
    // Obj Creation
    ptree jsonObj;
    std::istringstream is(ntwMsg);
    read_json (is, jsonObj);

    // assignment
    memberId = jsonObj.get<int>("memberId");
    address = jsonObj.get<std::string>("address");
    emailAddress = jsonObj.get<std::string>("emailAddress");
    name = jsonObj.get<std::string>("name");
    registerationDate = jsonObj.get<std::string>("registerationDate");
}

void Member::print()
{
    std::cout<<"Member Information"<<std::endl;
    std::cout<<"Member ID"<<memberId<<std::endl;
    std::cout<<"Name"<<name<<std::endl;
    std::cout<<"Address"<<address<<std::endl;
    std::cout<<"Email"<<emailAddress <<std::endl;
    std::cout<<"Registered date"<<registerationDate<<std::endl;
}
