#include "RequestResult.h"
#include <vector>

RequestResult::RequestResult()
{
    //ctor
}

RequestResult::~RequestResult()
{
    //dtor
}

void RequestResult::deSerialize(std::string ntwMsg)
{
// Obj Creation
    ptree jsonObj;
    std::istringstream is(ntwMsg);
    read_json (is, jsonObj);

    // assignment
    //vectorResponse = jsonObj.get<std::vector>("response");
    response= jsonObj.get<std::string>("response");
}
