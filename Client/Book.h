#ifndef BOOK_H
#define BOOK_H
#include "PureMessage.h"
#include <string.h>
#include <map>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

class Book: public PureMessage
{
    friend class boost::serialization::access;
public:
    Book();
    virtual  std::string serialize();
    void setISBN(std::string test);
    void setWriter(std::string test);
    void setTitle(std::string test);
    void setPublisher(std::string test);
    void setPubYear(std::string test);
    void setBorrowed(bool test);
    void setBookId(int test);
    std::string serialize(std::map <int,Book> bookData);
    void deSerialize(std::string ntwMsg);
    std::map<int,Book> deSerializeArray(std::string ntwMsg);
    void print();

    template<typename Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & bookId;
        ar & borrowed;
        ar & ISBN;
        ar & publishedYear;
        ar & publisher;
        ar & title;
        ar & writer;
    }


protected:
private:
    int bookId;
    bool borrowed;
    std::string ISBN;
    std::string publishedYear;
    std::string publisher;
    std::string title;
    std::string writer;

};

#endif // BOOK_H
