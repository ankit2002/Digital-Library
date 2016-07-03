#ifndef BORROW_H
#define BORROW_H

#include "PureMessage.h"
#include "Book.h"
#include "Member.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

class Borrow : PureMessage
{
public:
    Borrow();
    virtual ~Borrow();
    virtual std::string serialize();
    std::string serialize(std::map <int,Borrow> borrowData);
    void deSerialize(std::string ntwMsg);

    // setter
    void setBook(Book book);
    void setMember(Member member);
    void setBorrowingDate(std::string date);

    // getter
    Book getBook();
    Member getMember();
    std::string getBorrowingDate();

protected:
private:
    std::string borrowDate;
    Book borrowedBook;
    Member borrowingMember;
};

#endif // BORROW_H
