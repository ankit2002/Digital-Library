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

class Borrow : public PureMessage
{
public:
    Borrow();
    virtual ~Borrow();

    virtual std::string serialize();
    void deSerialize(std::string ntwMsg);
    Member getMember();
    Book getBook();
    std::string getBorrowingDate();
    void setBorrowingDate(std::string date);
    void setMember(Member member);
    void setBook(Book book);
    void print();
protected:
private:
    std::string borrowDate;
    Book borrowedBook;
    Member borrowingMember;
};

#endif // BORROW_H
