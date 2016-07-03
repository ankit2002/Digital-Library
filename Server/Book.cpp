#include "Book.h"

Book::Book()
{
    //ctor
}

std::string Book::serializeJson()
{
    std::string serializedBook;

    ptree pt;

    pt.put ("ISBN",ISBN);
    pt.put ("bookId", bookId);
    pt.put ("isBorrowed",borrowed);
    pt.put ("publisedYear", publishedYear);
    pt.put ("publisher", publisher);
    pt.put ("title", title);
    pt.put ("writer", writer);

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedBook = buf.str();

    return serializedBook;
}


std::string Book::serializeJson(std::map <int,Book> bookData)
{
    std::string serializedBook;
    std::string completeJson;

    typedef std::map<int,Book>::iterator it_type;

    for(it_type book = bookData.begin(); book != bookData.end(); book++) {
        Book bookObj;
        bookObj = book->second;
        std::string jsonStr = bookObj.serializeJson();
        completeJson += jsonStr;
    }

    ptree pt;
    pt.put ("response",completeJson);

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedBook = buf.str();

    return serializedBook;
}

void Book::setISBN(std::string test){
    ISBN = test;
}

void Book::setBookId(int test){
    bookId = test;
}


void Book::setBorrowed(bool test){
    borrowed = test;
}


void Book::setPubYear(std::string test){
    publishedYear = test;
}


void Book::setPublisher(std::string test){
    publisher = test;
}


void Book::setTitle(std::string test){
title = test;
}

void Book::setWriter(std::string test){
    writer = test;
}

// Getter Method
int Book::getBookId(){
    return bookId;
}

// Getter Method
bool Book::getBorrowedStatus(){
    return borrowed;
}

void Book::deSerializeJson(std::string ntwMsg)
{
    // Obj Creation
    ptree jsonObj;
    std::istringstream is(ntwMsg);
    read_json (is, jsonObj);

    // assignment
    bookId = jsonObj.get<int>("bookId");
    ISBN = jsonObj.get<std::string>("ISBN");
    borrowed = jsonObj.get<bool>("isBorrowed");
    publishedYear = jsonObj.get<std::string>("publisedYear");
    publisher = jsonObj.get<std::string>("publisher");
    title = jsonObj.get<std::string>("title");
    writer = jsonObj.get<std::string>("writer");
}