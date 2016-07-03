#ifndef UIENTRY_H
#define UIENTRY_H
#include "Book.h"
#include "Member.h"


class UIEntry
{
public:
    UIEntry();
    virtual ~UIEntry();
    Book EnterBookId();
    Book EnterBook();
    Member EnterMember();
    Member EnterMemberID();
    void ShowMenu();
protected:
private:
};

#endif // UIENTRY_H
