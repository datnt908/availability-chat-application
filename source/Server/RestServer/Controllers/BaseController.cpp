#include "BaseController.h"

namespace Server::RestServer::Controllers
{
    BaseController::BaseController() {}
    BaseController::~BaseController() {}
    void BaseController::setEndpoint(const string &value)
    {
        uri endpointURI(value);
        uri_builder endpointBuilder;

        endpointBuilder.set_scheme(endpointURI.scheme());
        endpointBuilder.set_host(endpointURI.host());
        endpointBuilder.set_port(endpointURI.port());
        endpointBuilder.set_path(endpointURI.path());

        _listener = http_listener(endpointBuilder.to_uri());
    }
    string BaseController::getEndpoint() const
    {
        return _listener.uri().to_string();
    }
    pplx::task<void> BaseController::accept()
    {
        initRestOpHandlers();
        return _listener.open();
    }
    pplx::task<void> BaseController::shutdown()
    {
        return _listener.close();
    }
    vector<utility::string_t> BaseController::requestPath(const http_request &message)
    {
        auto relativePath = uri::decode(message.relative_uri().path());
        return uri::split_path(relativePath);
    }
} // namespace Server::RestServer::Controllers
