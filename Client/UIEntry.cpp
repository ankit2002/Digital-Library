#include "UIEntry.h"
#include <cstdlib>

UIEntry::UIEntry()
{
    //ctor
}

UIEntry::~UIEntry()
{
    //dtor
}

void UIEntry::ShowMenu()
{
//    std::system ("clear");
    std::cout<<"FH-Library System."<<std::endl;
    std::cout<<"List of commands:"<<std::endl;
    std::cout<<"1) LAB: List all books;"<<std::endl;
    std::cout<<"2) ANB: Add new book;"<<std::endl;
    std::cout<<"3) UEB: Update existing book;"<<std::endl;
    std::cout<<"4) BAB: Borrow a book;"<<std::endl;
    std::cout<<"5) RAB: Return a book;"<<std::endl;
    std::cout<<"6) SBB: Show borrowed books"<<std::endl;
    std::cout<<"7) LAM: List all members;"<<std::endl;
    std::cout<<"8) ANM: Add new member;"<<std::endl;
    std::cout<<"9) Exit;"<<std::endl;

    std::cout<<"Enter your command:"<<std::endl;
}

Book UIEntry::EnterBook()
{
//    std::system ("clear");
    Book newBook;
    std::cout<<"Enter the book information: "<<std::endl;

    int id;
    std::cout<<"Book ID: ";
    std::cin>>id;
    newBook.setBookId(id);

    std::string title;
    std::cout<<"Titel: ";
    std::cin>>title;
    newBook.setTitle(title);

    std::string isbn;
    std::cout<<"ISBN: ";
    std::cin>>isbn;
    newBook.setISBN(isbn);

    std::string writer;
    std::cout<<"Writer: ";
    std::cin>>writer;
    newBook.setWriter(writer);

    std::string publisher;
    std::cout<<"Publisher: ";
    std::cin>>publisher;
    newBook.setPublisher(publisher);

    std::string publishedYear;
    std::cout<<"Published Year: ";
    std::cin>>publishedYear;
    newBook.setPubYear(publishedYear);

    newBook.setBorrowed(false);

    return newBook;
}

Book UIEntry::EnterBookId()
{
//    std::system ("clear");
    Book newBook;
    std::cout<<"Enter the book information: "<<std::endl;

    int id;
    std::cout<<"Book ID: ";
    std::cin>>id;
    newBook.setBookId(id);

    return newBook;
}


Member UIEntry::EnterMember()
{
//    std::system ("clear");
    Member newMem;
    std::cout<<"Enter the member information: "<<std::endl;

    int id;
    std::cout<<"Member ID: ";
    std::cin>>id;
    newMem.setMemberId(id);

    std::string name;
    std::cout<<"Name: ";
    std::cin>>name;
    newMem.setName(name);

    std::string address;
    std::cout<<"Adress: ";
    std::cin>>address;
    newMem.setAddress(address);

    std::string email;
    std::cout<<"Email: ";
    std::cin>>email;
    newMem.setEmailAddress(email);

    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
    std::string strDateCurrent(buffer);

    newMem.setRegistrationDate(strDateCurrent);

    return newMem;
}


Member UIEntry::EnterMemberID()
{
//    std::system ("clear");
    Member newMem;
    std::cout<<"Enter the member information: "<<std::endl;

    int id;
    std::cout<<"Member ID: ";
    std::cin>>id;
    newMem.setMemberId(id);

    return newMem;
}
