#include "RestServerController.h"

namespace Server::RestServer
{
    RestServerController::RestServerController() {}
    RestServerController::~RestServerController() {}

    void RestServerController::initRestOpHandlers()
    {
        _listener.support(methods::GET, std::bind(&RestServerController::handleGet, this, std::placeholders::_1));
        _listener.support(methods::PUT, std::bind(&RestServerController::handlePut, this, std::placeholders::_1));
        _listener.support(methods::POST, std::bind(&RestServerController::handlePost, this, std::placeholders::_1));
        _listener.support(methods::DEL, std::bind(&RestServerController::handleDelete, this, std::placeholders::_1));
    }

    void RestServerController::handleGet(http_request message)
    {
        auto path = requestPath(message);
        if (!path.empty())
        {
            if (path[0] == "service" && path[1] == "test")
            {
                auto response = json::value::object();
                response["version"] = json::value::string("0.1.1");
                response["status"] = json::value::string("ready!");
                message.reply(status_codes::OK, response);
                return;
            }
        }
        message.reply(status_codes::NotFound);
    }

    void RestServerController::handlePut(http_request message)
    {
        message.reply(status_codes::NotImplemented, responseNotImplement(methods::PUT));
    }

    void RestServerController::handlePost(http_request message)
    {
        message.reply(status_codes::NotImplemented, responseNotImplement(methods::POST));
    }

    void RestServerController::handleDelete(http_request message)
    {
        message.reply(status_codes::NotImplemented, responseNotImplement(methods::DEL));
    }

    json::value RestServerController::responseNotImplement(const http::method &method)
    {
        auto response = json::value::object();
        response["serviceName"] = json::value::string("C++ Mircroservice Sample");
        response["http_method"] = json::value::string(method);
        return response;
    }
} // namespace Server::RestServer