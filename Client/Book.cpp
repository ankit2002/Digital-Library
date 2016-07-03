#include "Book.h"
#include <fstream>
#include <sstream>

// include headers that implement a archive in simple text format
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp>

Book::Book()
{
    //ctor
}

std::string Book::serialize()
{
    std::string serializedBook;

    ptree pt;

    pt.put ("ISBN",Book::ISBN);
    pt. put ("bookId", bookId);
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

std::string Book::serialize(std::map <int,Book> bookData)
{
    std::string serializedBook;
    std::string completeJson;

    typedef std::map<int,Book>::iterator it_type;

    for(it_type book = bookData.begin(); book != bookData.end(); book++)
    {
        Book bookObj;
        bookObj = book->second;
        std::string jsonStr = bookObj.serialize();
        completeJson += jsonStr;
    }

    ptree pt;
    pt.put ("networkMessage",completeJson);

    std::ostringstream buf;
    write_json (buf, pt, false);
    serializedBook = buf.str();

    return serializedBook;
}

void Book::setISBN(std::string test)
{
    ISBN = test;
}

void Book::setBookId(int test)
{
    bookId = test;
}


void Book::setBorrowed(bool test)
{
    borrowed = test;
}


void Book::setPubYear(std::string test)
{
    publishedYear = test;
}


void Book::setPublisher(std::string test)
{
    publisher = test;
}


void Book::setTitle(std::string test)
{
    title = test;
}

void Book::setWriter(std::string test)
{
    writer = test;
}

// Getter Method
/*
int Book::getBookId(){
    return bookId;
}*/

void Book::deSerialize(std::string ntwMsg)
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

void Book::print()
{
    std::cout<<"Book Information: "<<std::endl;
    std::cout<<"Book ID : "<<bookId<<std::endl;
    std::cout<<"Tile: "<<title<< std::endl;
    std::cout<<"ISBN: "<<ISBN<< std::endl;
    std::cout<<"Writer: "<<writer<< std::endl;
    std::cout<<"Publisher: "<<publisher<< std::endl;
    std::cout<<"Published year: "<<publishedYear<< std::endl;
}

std::map<int,Book> Book::deSerializeArray(std::string ntwMsg)
{
    std::map<int,Book> data;

    std::stringstream  ss;
    ss << ntwMsg;

    boost::archive::text_iarchive ia(ss);

    ia >> data;

    return data;

    /*
        std::stringstream  ss;

        ss<<ntwMsg;
        std::vector<Book> bookList;
        boost::archive::text_iarchive archive(ss);
        archive >> bookList;

        std::cout<<" testing size "<<bookList.size();
    */

    /*
        ptree jsonObj;
        std::istringstream is(ntwMsg);
        read_json (is, jsonObj);

        // assignment
        bookId = jsonObj.get<int>("bookId");
    */
}

