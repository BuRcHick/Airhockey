#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "SDL2/SDL.h"
#include "SDL2/SDL_render.h"

#include <stdio.h>
#include <string>

#define DEFAULT_WIDTH 720
#define DEFAULT_HEIGHT 480
#define DEFAULT_TITLE "Super Mega Game"

class Window
{
public:
    ~Window();

    Window(const Window &) = delete;
    Window &operator = (const Window &) = delete;
    Window(Window &&);
    Window &operator = (Window &&);

    static Window *create(const char *title);

    void handleEvent();
    void show();
    void update();

    bool changeTitle(const char* title);
    bool resize(int w, int h);
    bool setPos(int x, int y);

    SDL_Renderer *getRenderer() const { return m_rndr; }
    SDL_Window *getWindow() const { return m_wnd; }

protected:
    Window();
    Window(const char *title);

private:
    SDL_Renderer *m_rndr;
    SDL_Window *m_wnd;
    bool m_quit;
    int m_x, m_y, m_width, m_height;
    std::string m_title;

};

#endif /* __WINDOW_HPP__ */
