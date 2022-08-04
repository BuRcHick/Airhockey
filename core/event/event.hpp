#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include "SDL_events.h"
#include "game_event.hpp"
#include "logger/logger.hpp"

enum class EventType {
    SDL_Event,
    GameEvent
};

struct Event {
    union {
        SDL_Event sdl_event;
        GameEvent game_event;
    } data;

    EventType type;

    ~Event() {
    }
};

#endif /* __EVENT_HPP__ */
