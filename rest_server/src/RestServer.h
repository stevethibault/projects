#ifndef _REST_SERVER_HEADER_INCUDED
#define _REST_SERVER_HEADER_INCUDED

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Exception.h"
#include "Poco/ThreadPool.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include <iostream>
#include <sstream>

using namespace Poco;
using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;

class RestServer: public ServerApplication
{
public:
    RestServer() : _helpRequested(false)
    {
    }

    ~RestServer()
    {
    }

protected:
    void initialize(Application& self);

    void uninitialize();

    void defineOptions(OptionSet& options);

    void handleHelp(const string& name, const string& value);

    int main(const vector<string>& args);

private:
    bool _helpRequested;
};

#endif _REST_SERVER_HEADER_INCUDED
