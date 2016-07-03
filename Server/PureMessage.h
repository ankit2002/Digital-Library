#ifndef PUREMESSAGE_H
#define PUREMESSAGE_H

#include <iostream>

class PureMessage
{
public:
    PureMessage();
    virtual ~PureMessage();
    //virtual void test()=0;

    virtual std::string serialize()
    {
        return "PureMessage:message";
    }
protected:
private:
};

#endif // PUREMESSAGE_H
