#include "request_handler_echo.h"

namespace http {
namespace server {

	RequestHandler::Status EchoHandler::Init(const std::string& uri_prefix, const NginxConfig& config) {
		
	return RequestHandler::Status::OK;
	}


	RequestHandler::Status EchoHandler::HandleRequest(const Request& request, Response* response) {
	  	std::cout << "EchoHandler::HandleRequest called" << std::endl;
	  
	  	response->SetStatus(Response::ResponseCode::OK);
	  	response->AddHeader("Content-Type", "text/plain");
	  	response->AddHeader("Content-Length", std::to_string(request.raw_request().length()));
	  	response->SetBody(request.raw_request());
	  	response->SetVersion(request.version());
	  	
	return RequestHandler::Status::OK;
	}
	
} // namespace server
} // namespace http
