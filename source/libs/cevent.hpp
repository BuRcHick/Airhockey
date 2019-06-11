#ifndef CEVENT
#define CEVENT
#include "SDL2/SDL.h"
#include <stdio.h>

class CEvent
{
private:
	SDL_Event event;
	static int eventCode;
public:
	CEvent();
	~CEvent();
	CEvent(const CEvent&) = delete;
	CEvent& operator = (const CEvent&) = delete;
	CEvent(CEvent&&) = delete;
	const int getCode() const {return event.user.code;}
};

#endif //CEVENT