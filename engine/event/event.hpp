#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "SDL2/SDL_events.h"

enum class EventType {
    SDL_Event,
    GameEvent
};

struct Event {
    union {
        SDL_Event sdl_event;
    } data;

    EventType type;
};

#endif /* __EVENT_HPP__ */
