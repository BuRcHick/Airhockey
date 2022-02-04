#ifndef CWINDOW
#define CWINDOW
#include "SDL2/SDL.h"
#include <string>
#include <stdio.h>

class CWindow
{
private:
    SDL_Window* mWnd;
    SDL_Renderer* mRndr;
    int posX, posY, width, height;
public:
    bool quit;
    CWindow();
    ~CWindow();
    CWindow(const CWindow&) = delete;
    CWindow& operator = (const CWindow&) = delete;
    CWindow(CWindow &&);

    bool init(int initF, const std::string& title, int x, int y, int w, int h, int wndFlags);
    void handleEvent();
    bool show();

    SDL_Renderer* getRenderer()const {return mRndr; }
    SDL_Window* getWindow() const { return mWnd; }
    void update();
};
#endif
