#ifndef __FRAMEWORK_HPP__
#define __FRAMEWORK_HPP__

#include "game_objects/game_object.hpp"
#include "game_objects/hockey_striker.hpp"
#include "window/window.hpp"

#define WIDTH   700
#define HEIGHT  900

class Game {
public:
    ~Game();

    static Game* getGame();

    Window* getWindow() { return m_window; }

    void draw();

    bool init();

protected:
    Game();

private:
    Window* m_window;

    GameObject* m_striker_1;
    GameObject* m_striker_2;
    GameObject* m_puck;

    HitBox2D* m_topBorder;
    HitBox2D* m_buttomBorder;
    HitBox2D* m_leftBorder;
    HitBox2D* m_rightBorder;

    HitBox2D* m_leftGate;
    HitBox2D* m_rightGate;

    static Game* m_game;
};

namespace AirHockey {
    bool init();
    void handleEvent();
    bool update();
    void close();
}

#endif /* __FRAMEWORK_HPP__ */
