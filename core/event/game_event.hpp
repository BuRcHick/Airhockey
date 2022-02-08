#ifndef __GAME_EVENT_HPP__
#define __GAME_EVENT_HPP__

enum GameEventType {
    Play = 0,
    Stop,
    Tick,
};

struct GameEvent {
    GameEventType type;
};

#endif /* __GAME_EVENT_HPP__ */
