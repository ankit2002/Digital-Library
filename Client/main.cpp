#include <iostream>
#include <array>
#include <boost/asio.hpp>
#include "CommunicationManager.h"
#include "Book.h"
#include <stdio.h>
#include <ctime>
#include "UIEntry.h"

int main()
{
    try
    {

        UIEntry ui;
        ui.ShowMenu();

        int uCommand= -1;
        std::cout<<"Please select command number: ";
        std::cin>>uCommand;

        while(uCommand>0 && uCommand<=9)
        {
            std::cout<<"Your command: "<<uCommand<<std::endl;

            CommunicationManager cm;

            switch(uCommand)
            {
            case 1://List All Books
            {
                NetworkMessage nm;
                nm.Setcommand(Commands::LAB);
                RequestResult res= cm.sendMessage(nm);
                std::cout<<"Result: "<<res.response<<std::endl;

                std::cout<<"Press Enter to continue"<<std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            }
            case 2://Add New Book
            {
                Book bk=ui.EnterBook();

                NetworkMessage nm;
                nm.Setcommand(Commands::ANB);
                nm.setArgumentType(ArgumentTypes::BookType);
                nm.setBook(bk);
                nm.SetArgument(bk);
                RequestResult res= cm.sendMessage(nm);
                std::cout<<"Result: "<<res.response<<std::endl;

                std::cout<<"Press Enter to continue"<<std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            }
            case 3://Update Existing Book
            {
                Book bk=ui.EnterBook();

                NetworkMessage nm;
                nm.Setcommand(Commands::UEB);
                nm.setArgumentType(ArgumentTypes::BookType);
                nm.setBook(bk);
                nm.SetArgument(bk);
                RequestResult res= cm.sendMessage(nm);
                std::cout<<"Result: "<<res.response<<std::endl;

                std::cout<<"Press Enter to continue"<<std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            }
            case 4://Borrow a Book
            {
                Borrow br;

                time_t rawtime;
                struct tm * timeinfo;
                char buffer[80];

                time (&rawtime);
                timeinfo = localtime(&rawtime);

                strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
                std::string strDateCurrent(buffer);

                br.setBorrowingDate(strDateCurrent);

                Book bk;
                bk=ui.EnterBookId();

                br.setBook(bk);

                Member borrowingMember;
                borrowingMember=ui.EnterMemberID();

                NetworkMessage nm;
                nm.Setcommand(Commands::BAB);
                nm.setArgumentType(ArgumentTypes::BorrowType);
                nm.setBorrow(br);
                nm.SetArgument(br);
                RequestResult res= cm.sendMessage(nm);
                std::cout<<"Result: "<<res.response<<std::endl;

                std::cout<<"Press Enter to continue"<<std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            }
            case 5://Return a Book
            {
                Book bk;
                int id;
                std::cout<<"Enter book id:"<<std::endl;
                std::cin>>id;

                bk.setBookId(id);
                bk.setBorrowed(false);

                NetworkMessage nm;
                nm.Setcommand(Commands::RBB);
                nm.setArgumentType(ArgumentTypes::BookType);
                nm.setBook(bk);
                nm.SetArgument(bk);
                RequestResult res= cm.sendMessage(nm);
                std::cout<<"Result: "<<res.response<<std::endl;

                std::cout<<"Press Enter to continue"<<std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            }
            case 6://Show Borrowed Books
            {
                NetworkMessage nm;
                nm.Setcommand(Commands::SBB);
                RequestResult res= cm.sendMessage(nm);
                std::cout<<"Result: "<<res.response<<std::endl;

                std::cout<<"Press Enter to continue"<<std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            }
            case 7://List all the members
            {
                NetworkMessage nm;
                nm.Setcommand(Commands::LAM);
                RequestResult res= cm.sendMessage(nm);
                std::cout<<"Result: "<<res.response<<std::endl;

                std::cout<<"Press Enter to continue"<<std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            }
            case 8://Add New Member
            {
                Member newMember;
                newMember=ui.EnterMember();

                NetworkMessage nm;
                nm.Setcommand(Commands::ANM);
                nm.setArgumentType(ArgumentTypes::MemberType);
                nm.setMember(newMember);
                //nm.SetArgument(newMember);
                RequestResult res= cm.sendMessage(nm);
                std::cout<<"Result: "<<res.response<<std::endl;

                std::cout<<"Press Enter to continue"<<std::endl;
                std::cin.ignore();
                std::cin.ignore();
                break;
            }
            default:

                std::cout<<"Thank you for using our system!"<<std::endl;
                getchar();
                exit(0);
            }
            ui.ShowMenu();
            std::cout<<std::endl<<"Please select command number: ";
            std::cin>>uCommand;
        }


    }
    catch(std::exception const &ex)
    {
        std::cerr<<ex.what()<<std::endl;
    }
}

