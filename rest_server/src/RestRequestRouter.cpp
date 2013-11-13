#include "TrainingManagerRestlet.h"
#include "RestRequestRouter.h"

HTTPRequestHandler* RestRequestRouter::createRequestHandler(const HTTPServerRequest& request)
{
    Path path(request.getURI());

    return new TrainingManagerRestlet(path);
}

HTTPRequestHandler* GetRestletForPath(Path& path)
{
    return new TrainingManagerRestlet(path);
}
