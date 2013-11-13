#ifndef _TRAINING_MANAGER_RESTLET_INCLUDED
#define _TRAINING_MANAGER_RESTLET_INCLUDED

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

class TrainingManagerRestlet : public HTTPRequestHandler
{
    public:
        TrainingManagerRestlet(Path& path): _path(path)
        {
        }

        void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response);
    private:
        Path& _path;
};

#endif
