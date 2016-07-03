#include "NetworkMessage.h"


#include "PureMessage.h"
#include "Book.h"
#include "Member.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

NetworkMessage::NetworkMessage()
{
    //ctor
}

NetworkMessage::~NetworkMessage()
{
    //dtor
}

std::string NetworkMessage::serialize()
{
    std::string serializedMessage;

    ptree pt;

    std::string strMsg="";

    switch(argumentType)
    {
    case ArgumentTypes::BookType:
        strMsg=getBook().serialize();
        break;
    case ArgumentTypes::BorrowType:
        strMsg=getBorrow().serialize();
        break;
    case ArgumentTypes::MemberType:
        strMsg=getMember().serialize();
    }

    pt.put ("networkMessage", strMsg);
    pt.put ("command",getCommadStr());

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedMessage = buf.str();

    return serializedMessage;
}

PureMessage NetworkMessage::GetArgument()
{
    return argument;
}
void NetworkMessage::SetArgument(PureMessage val)
{
    argument = val;
}
Commands NetworkMessage::Getcommand()
{
    return command;
}
void NetworkMessage::Setcommand(Commands val)
{
    command = val;
}
void NetworkMessage::setArgumentType(ArgumentTypes aty)
{
    argumentType=aty;
}
ArgumentTypes NetworkMessage::getArgumentType()
{
    return argumentType;
}
void NetworkMessage::setBook(Book b)
{
    book=b;
}
Book NetworkMessage::getBook()
{
    return book;
}
void NetworkMessage::setMember(Member m)
{
    member=m;
}
Member NetworkMessage::getMember()
{
    return member;
}
void NetworkMessage::setBorrow(Borrow b)
{
    borrow=b;
}
Borrow NetworkMessage::getBorrow()
{
    return borrow;
}

std::string NetworkMessage::getCommadStr()
{
    switch(command)
    {
    case Commands::ANB:
        return "ANB";
    case Commands::LAB:
        return "LAB";
    case Commands::UEB:
        return "UEB";
    case Commands::BAB:
        return "BAB";
    case Commands::RBB:
        return "RBB";
    case Commands::SBB:
        return "SBB";
    case Commands::LAM:
        return "LAM";
    case Commands::ANM:
        return "ANM";
    }
}
