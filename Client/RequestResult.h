#ifndef REQUESTRESULT_H
#define REQUESTRESULT_H

#include <string>
#include <vector>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

class RequestResult
{
    public:
        RequestResult();
        virtual ~RequestResult();
        std::string response;
        std::vector<std::string> vectorResponse;


void deSerialize(std::string ntwMsg);
    protected:
    private:
};

#endif // REQUESTRESULT_H
