#include "cevent.hpp"
int CEvent::eventCode = 0;

CEvent::CEvent(/* args */)
{
	++eventCode;
	event.user.code = eventCode;
	event.type = SDL_USEREVENT;
}

CEvent::~CEvent()
{
	--eventCode;
}