#include <boost/asio.hpp>
#include <thread>
#include <atomic>
#include <memory>
#include <iostream>
#include <sstream>

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/map.hpp>


#include <map>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "Book.h"
#include "Member.h"
#include "Borrow.h"

using namespace boost;
using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;
using namespace std;


class Memory{
    std::map<int,Book> bookMap;
    std::map<int,Member> memberMap;
    std::map<int,Borrow> borrowMap;

public:
    // Method to add Books in Memory
    std::string addBookInMemory(Book book){
        bookMap[book.getBookId()] = book;
        return "Book Added";
    }

    //Method to update Books
    std::string updateBookInMemory(Book book){

        if(bookMap.find(book.getBookId()) != bookMap.end()){
            bookMap[book.getBookId()] = book;
            return "Book Updated";
        } else{
            // Not found
            return "No entry to updated";
        }
    }

    // Method to show All Books
    std::map<int, Book> listAllBooks(){
        map<int, Book> bookNotBorrowed;
        typedef std::map<int,Book>::iterator it_type;

        for(it_type book = bookMap.begin(); book != bookMap.end(); book++) {
            if(!(book->second.getBorrowedStatus()))
            {
                bookNotBorrowed[book->second.getBookId()] = book->second;
            }
        }
        return bookNotBorrowed;
    }

    // Method to add Books in Memory
    std::string addMemberInMemory(Member member){
        memberMap[member.getMemberId()] = member;
        return "Member Added";
    }

    // Method to show All Members
    std::map<int, Member> listAllMembers(){
        return memberMap;
    }

    // Method to show All Borrowed books
    std::map<int, Borrow> showAllBorrowBooks(){
        return borrowMap;
    }


    // Method to Add Borrowed books
    std::string addBorrowedBookInMemory(Borrow borrow){

        Book book;
        book = borrow.getBook();
        if(bookMap.find(book.getBookId()) != bookMap.end()){
            bookMap[book.getBookId()] = book;
        } else{
            // Not found
            return "No entry to updated";
        }

        borrowMap[borrow.getBook().getBookId()] = borrow;
        return "Book Borrowed";
    }

    // Method to DeleteBorrowBook
    std::string deleteBorrowBook(Book bookObj){
        bookMap[bookObj.getBookId()] = bookObj;
        borrowMap.erase(bookObj.getBookId());
        return "Book Returned";
    }
};

static Memory memory;

class Service {
public:
    Service(){}

    void HandleClient(asio::ip::tcp::socket& sock) {
        try {
            asio::streambuf request;
            boost::system::error_code ec;
            asio::read_until(sock, request, '\n');

            // to print
            std::istream inputReq(&request);
            std::string jsonStr;
            std::getline(inputReq, jsonStr);

            // Read json.
            ptree jsonObj;
            std::istringstream is(jsonStr);
            read_json (is, jsonObj);
            std::string command = jsonObj.get<std::string>("command");
            std::string networkMessage = jsonObj.get<std::string>("networkMessage");
            std::cout<<" command "<<command<<std::endl;


            if (command == "ANB") // Add new Book
            {
                Book book;
                ptree jsonInnerObj;
                book.deSerializeJson(networkMessage);
                string msg = memory.addBookInMemory(book);
                jsonInnerObj.put ("response",msg);
                ostringstream buf;
                write_json (buf, jsonInnerObj, false);
                write(sock, asio::buffer(buf.str() + "\n"));
            }
            else if(command == "LAB") // List All Book
            {
                Book book;
                map<int, Book> listOfBooks = memory.listAllBooks();
                string completeJson = book.serializeJson(listOfBooks);

//                std::stringstream ss;
//                boost::archive::text_oarchive oa(ss);
//                oa & listOfBooks;
//
//                ptree pt;
//                pt.put ("response",ss.str());
//
//                std::ostringstream buf;
//                write_json (buf, pt, false);
//                string completeJson = buf.str();

//                std::cout<<"COmplete record of Json"<< completeJson<<std::endl;
                write(sock, asio::buffer(completeJson + "\n"));
            }
            else if(command == "UEB") // Update Book
            {
                Book book;
                ptree jsonInnerObj;
                book.deSerializeJson(networkMessage);
                string msg = memory.updateBookInMemory(book);
                jsonInnerObj.put ("response",msg);
                ostringstream buf;
                write_json (buf, jsonInnerObj, false);
                write(sock, asio::buffer(buf.str() + "\n"));
            }
            else if(command == "BAB") // Borrow Book
            {
                ptree jsonInnerObj;
                Borrow borrow;
                borrow.deSerialize(networkMessage);
                string msg = memory.addBorrowedBookInMemory(borrow);
                jsonInnerObj.put ("response",msg);
                ostringstream buf;
                write_json (buf, jsonInnerObj, false);
                write(sock, asio::buffer(buf.str() + "\n"));
            }
            else if(command == "RBB") // Return Brw Book
            {
                ptree jsonInnerObj;
                Book book;
                book.deSerializeJson(networkMessage);
                string msg = memory.deleteBorrowBook(book);
                jsonInnerObj.put ("response",msg);
                ostringstream buf;
                write_json (buf, jsonInnerObj, false);
                write(sock, asio::buffer(buf.str() + "\n"));
            }
            else if(command == "SBB") // Show Brw Book
            {
                Borrow borrowObj;
                map<int, Borrow> listOfBorrowedBook = memory.showAllBorrowBooks();
                string completeJson = borrowObj.serialize(listOfBorrowedBook);

                // Sending response.
                write(sock, asio::buffer(completeJson + "\n"));

            }
            else if(command == "LAM") // List All Member
            {
                Member member;
                map<int, Member> listOfMembers = memory.listAllMembers();
                string completeJson = member.serialize(listOfMembers);

                // Sending response.
                write(sock, asio::buffer(completeJson + "\n"));

            }
            else if(command == "ANM") // Add New Member
            {
                ptree jsonInnerObj;
                Member member;
                member.deSerialize(networkMessage);
                string msg = memory.addMemberInMemory(member);
                jsonInnerObj.put ("response",msg);

                // Sending response.
                ostringstream buf;
                write_json (buf, jsonInnerObj, false);
                write(sock, asio::buffer(buf.str() + "\n"));

            }
        }
        catch (system::system_error&e) {
            std::cout  << "Error occured in Service = " <<e.code() << " and Message: " <<e.what();
        }
    }
};





class Acceptor {
public:
    Acceptor(asio::io_service&ios, unsigned short port_num) :
            m_ios(ios),
            m_acceptor(m_ios,
                       asio::ip::tcp::endpoint(
                               asio::ip::address_v4::any(),
                               port_num))
    {
        m_acceptor.listen();
    }
    void Accept() {
        asio::ip::tcp::socket sock(m_ios);
        m_acceptor.accept(sock);
        Service svc;
        svc.HandleClient(sock);
    }
private:
    asio::io_service &m_ios;
    asio::ip::tcp::acceptor m_acceptor;
};


class Server {
public:
    Server() : m_stop(false) {}
    void Start(unsigned short port_num) {
        m_thread.reset(new std::thread([this, port_num]() {
            Run(port_num);
        }));
    }
    void Stop() {
        m_stop.store(true);
        m_thread->join();
    }

    void makeThreadJoin(){
        m_thread->join();
    }

private:
    void Run(unsigned short port_num) {
        Acceptor acc(m_ios, port_num);
        while (!m_stop.load()) {
            acc.Accept();
        } }
    std::unique_ptr<std::thread>m_thread;
    std::atomic<bool> m_stop;
    asio::io_service m_ios;
};



int main() {
    unsigned short port_num = 8000;
    try {
        Server srv;
        srv.Start(port_num);
        srv.makeThreadJoin();
    }
    catch (system::system_error&e) {
        std::cout  << "Error occured in server main Error code = " <<e.code()<<" and message "<<e.what();
    }
    return 0;
}