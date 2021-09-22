#include "cwindow.hpp"

/**
 * Constructor default
 */
CWindow::CWindow(){
    mWnd = nullptr;
    mRndr = nullptr;
    posX = posY = 0;
    width = height = 100;
}

/**
 * Moving Contructor
 */
CWindow::CWindow(CWindow && wnd){
    if(mWnd) SDL_DestroyWindow(mWnd);
    if(mRndr) SDL_DestroyRenderer(mRndr);
    mWnd = wnd.mWnd;
    mRndr = wnd.mRndr;
    posX = wnd.posX;
    posY = wnd.posY;
    width = wnd.width;
    height = wnd.height;
    wnd.mWnd = nullptr;
    wnd.mRndr = nullptr;
}

CWindow::~CWindow(){
    printf("Window delted successfuly!\n");
    SDL_DestroyRenderer(mRndr);
    SDL_DestroyWindow(mWnd);
}

/**
 * Initialization subsystems, Window and Renderer
 */
bool CWindow::init(
    u_int32_t initF, 
    const std::string& title, 
    int x, 
    int y, 
    int w, 
    int h, 
    u_int32_t wndFlags){
    if(SDL_Init(initF) != 0){
        perror("Error! SDL_Init...");
        return false;
    }
    if(!(mWnd = SDL_CreateWindow(title.c_str(),x,y,w,h,wndFlags))){
        perror("Error! The window creating failed...");
        return false;
    }
    if(!(mRndr = SDL_CreateRenderer(mWnd,-1,0))){
        perror("Error! The renderer creating failed...");
        return false;
    }
    return true;
}

/**
 * Updating the renderer
 */
void CWindow::update(){
    SDL_RenderClear(mRndr);
    SDL_RenderPresent(mRndr);
}

/**
 * Handling events
 */
void CWindow::handleEvent(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        quit = true;
        SDL_Quit();
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT:
            printf("Right\n");
            break;
        
        default:
            break;
        }
        break;
    default:
        break;
    }
}

