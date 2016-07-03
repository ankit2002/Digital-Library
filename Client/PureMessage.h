#ifndef PUREMESSAGE_H
#define PUREMESSAGE_H

#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;


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
