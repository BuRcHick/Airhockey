#ifndef __FRAMEWORK_HPP__
#define __FRAMEWORK_HPP__

#include "game_objects/game_object.hpp"
#include "game_objects/hockey_striker.hpp"
#include "window/window.hpp"

class Game {
public:
    ~Game();

    Window* m_window;

    GameObject* m_striker_1;
    GameObject* m_striker_2;
    GameObject* m_puck;

    GameObject* m_topBorder;
    GameObject* m_buttomBorder;
    GameObject* m_leftBorder;
    GameObject* m_rightBorder;

    GameObject* m_leftGate;
    GameObject* m_rightGate;

    static Game* getGame();

protected:
    Game();

private:
    static Game* m_game;
};

namespace AirHockey {
    bool init();
    void handleEvent();
    bool update();
    void close();
}

#endif /* __FRAMEWORK_HPP__ */
