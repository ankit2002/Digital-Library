#include "Member.h"
#include <map>

Member::Member()
{
    //ctor
}

Member::~Member()
{
    //dtor
}

std::string Member::serialize()
{
    std::string serializedMember;

    ptree pt;

    pt.put ("memberId",memberId);
    pt.put ("address", address);
    pt.put ("emailAddress", emailAddress);
    pt.put ("name", name);
    pt.put ("registerationDate", registerationDate);

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedMember = buf.str();

    return serializedMember;
}

std::string Member::serialize(std::map <int,Member> memberData)
{
    std::string serializedBook;
    std::string completeJson;

    typedef std::map<int,Member>::iterator it_type;

    for(it_type member = memberData.begin(); member != memberData.end(); member++) {
        Member memberObj;
        memberObj = member->second;
        std::string jsonStr = memberObj.serialize();
        completeJson += jsonStr;
    }

    ptree pt;
    pt.put ("response",completeJson);

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedBook = buf.str();

    return serializedBook;
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