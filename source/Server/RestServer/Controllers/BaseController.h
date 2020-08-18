#pragma once

#include <string>
#include <vector>
#include <cpprest/http_listener.h>
#include <pplx/pplxtasks.h>

using namespace std;
using namespace web;
using namespace http;
using namespace http::experimental::listener;

namespace Server::RestServer::Controllers
{
    class HttpMethodController
    {
    public:
        virtual void handleGet(http_request message) = 0;
        virtual void handlePost(http_request message) = 0;
        virtual void handlePut(http_request message) = 0;
        virtual void handleDelete(http_request message) = 0;
    };

    class BaseController
    {
    protected:
        http_listener _listener; // main micro service network endpoint

    public:
        BaseController();
        ~BaseController();

        void setEndpoint(const string &value);
        string getEndpoint() const;
        pplx::task<void> accept();
        pplx::task<void> shutdown();
        virtual void initRestOpHandlers() = 0;
        vector<utility::string_t> requestPath(const http_request &message);
    };
} // namespace Server::RestServer::Controllers
