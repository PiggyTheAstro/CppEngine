#include <core/serviceHandler.h>

ServiceHandler* ServiceHandler::instance;

ServiceHandler::ServiceHandler()
{
	instance = this;
}