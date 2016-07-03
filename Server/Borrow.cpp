#include "Borrow.h"

Borrow::Borrow()
{
    //ctor
}

Borrow::~Borrow()
{
    //dtor
}


std::string Borrow::serialize()
{
    std::string serializedBorrow;

    ptree pt;
    pt.put ("borrowDate",borrowDate);
    pt.put ("borrowedBook", Borrow::borrowedBook.serializeJson());
    pt.put ("borrowingMember", Borrow::borrowingMember.serialize());

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedBorrow = buf.str();

    return serializedBorrow;
}

std::string Borrow::serialize(std::map <int,Borrow> borrowData)
{
    std::string serializedBook;
    std::string completeJson;

    typedef std::map<int,Borrow>::iterator it_type;

    for(it_type borrow = borrowData.begin(); borrow != borrowData.end(); borrow++) {
        Borrow borrowObj;
        borrowObj = borrow->second;
        std::string jsonStr = borrowObj.serialize();
        completeJson += jsonStr;
    }

    ptree pt;
    pt.put ("response",completeJson);

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedBook = buf.str();

    return serializedBook;
}

void Borrow::setBook(Book book){
    borrowedBook = book;
}

void Borrow::setMember(Member member){
    borrowingMember = member;
}

void Borrow::setBorrowingDate(std::string date) {
    borrowDate = date;
}

std::string Borrow::getBorrowingDate() {
    return borrowDate;
}

// Getter Method
Book Borrow::getBook(){
    return borrowedBook;
}

Member Borrow::getMember(){
    return borrowingMember;
}

void Borrow::deSerialize(std::string ntwMsg)
{
    // Obj Creation
    ptree jsonObj;
    std::istringstream is(ntwMsg);
    read_json (is, jsonObj);

    // assignment
    borrowDate = jsonObj.get<std::string>("borrowDate");

    Book bw;
    bw.deSerializeJson(jsonObj.get<std::string>("borrowedBook"));
    borrowedBook = bw;

    Member brw;
    brw.deSerialize(jsonObj.get<std::string>("borrowingMember"));
    borrowingMember = brw;
}