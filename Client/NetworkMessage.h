#ifndef NETWORKMESSAGE_H
#define NETWORKMESSAGE_H

#include "PureMessage.h"
#include "Book.h"
#include "Member.h"
#include "Borrow.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


enum class Commands
{
    LAB,ANB,UEB,BAB,RBB,SBB,LAM,ANM
};

enum class ArgumentTypes
{
    BookType,MemberType,BorrowType
};

class NetworkMessage
{
public:
    NetworkMessage();
    virtual ~NetworkMessage();
    PureMessage GetArgument();
    void SetArgument(PureMessage val);
    Commands Getcommand();
    void Setcommand(Commands val);
    std::string serialize();
    void setArgumentType(ArgumentTypes aty);
    ArgumentTypes getArgumentType();
    void setBook(Book b);
    Book getBook();
    void setMember(Member b);
    Member getMember();
    void setBorrow(Borrow b);
    Borrow getBorrow();
protected:
private:
    PureMessage argument;
    Book book;
    Member member;
    Borrow borrow;
    ArgumentTypes argumentType;
    Commands command;
    std::string getCommadStr();
    std::string response;
};

#endif // NETWORKMESSAGE_H
