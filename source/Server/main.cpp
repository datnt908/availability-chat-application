#include <iostream>

#include "MyLibrary.h"
#include "RestServerController.h"

using namespace std;
using namespace MyLibrary;
using namespace Server::RestServer;

RestServerController *RestServer = NULL;

int initializeRestServer();
void shutdownAllServer();

int main(int argc, const char *argv[])
{
    int result = RESULT_CODE::RESULT_UNKNOWN;
    InterruptHandler::hookSIGINT();

    if ((result = initializeRestServer()))
        return result;

    InterruptHandler::waitForUserInterrupt();
    shutdownAllServer();

    return RESULT_CODE::RESULT_SUCCESS;
}

int initializeRestServer()
{
    printHorizontalLine();
    cout << "Modern C++ Rest API server now initializing for requests...\n";
    RestServer = new RestServerController();

    string endpoint = "http://";
    endpoint.append(REST_SERV_IP + string(":") + REST_SERV_PORT);
    endpoint.append("/api");
    RestServer->setEndpoint(endpoint);

    try
    {
        RestServer->accept().wait();
        cout << "Modern C++ Rest API server now listening for requests at: "
             << RestServer->getEndpoint() << '\n';
        printHorizontalLine();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return RESULT_CODE::REST_SERV_INIT_ERR;
    }

    return RESULT_CODE::RESULT_SUCCESS;
}

void shutdownAllServer()
{
    if (RestServer != NULL)
    {
        cout << "\nModern C++ Rest API server shutdown\n";
        RestServer->shutdown().wait();
        delete RestServer;
    }
    printHorizontalLine();
}