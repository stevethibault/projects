#include "RestServer.h"
#include "RestRequestRouter.h""

void RestServer::initialize(Application& self)
{
    loadConfiguration();
    ServerApplication::initialize(self);
}

void RestServer::uninitialize()
{
    ServerApplication::uninitialize();
}

void RestServer::defineOptions(OptionSet& options)
{
    ServerApplication::defineOptions(options);
    options.addOption(
        Option("help", "h", "display command line argument help information")
        .required(false)
        .repeatable(false)
        .callback(OptionCallback<RestServer>(this, &RestServer::handleHelp)));
}

void RestServer::handleHelp(const string& name, const string& value)
{
    HelpFormatter helpFormatter(options());
    helpFormatter.setCommand(commandName());
    helpFormatter.setUsage("OPTIONS");
    helpFormatter.setHeader("A rest server that serves rest data and handles rest udpates and commands");
    helpFormatter.format(std::cout);
    stopOptionsProcessing();
    _helpRequested = true;
}

int RestServer::main(const vector<string>& args)
{
    if (!_helpRequested)
    {
        unsigned short port = (unsigned short)config().getInt("RestServer.port", 9980);
        std::string format(config().getString("RestServer.format",
                           DateTimeFormat::SORTABLE_FORMAT));


        ServerSocket serverSocket(port);
        HTTPServer server(new RestRequestRouter(), serverSocket,
                          new HTTPServerParams);
        server.start();
        logger().information("Welcome to PatternRester, the server is running in port 9980.");
        waitForTerminationRequest();
        server.stop();
    }
    return Application::EXIT_OK;
}


int main(int argc, char** argv)
{
    RestServer app;
    return app.run(argc, argv);
}
