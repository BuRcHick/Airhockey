#include "window.hpp"

#include "logger/logger.hpp"

#include <cstdint>
#include <cstdio>

Window::Window()
{
    m_wnd = nullptr;
    m_rndr = nullptr;
    m_x = m_y = 0;
    m_width = DEFAULT_WIDTH;
    m_height = DEFAULT_HEIGHT;
    m_title = DEFAULT_TITLE;

    LOG_DEBUG("Window succesfully created\n");

}

Window::Window(const char *title)
    : Window()
{
    if (nullptr != title) {
        m_title = title;
    }
}

Window::Window(Window &&wnd)
{
    *this = std::move(wnd);
}

Window& Window::operator=(Window &&wnd)
{
    if(nullptr != m_rndr) {
        SDL_DestroyRenderer(m_rndr);
    }

    if(nullptr != m_wnd) {
        SDL_DestroyWindow(m_wnd);
    }


    m_rndr = wnd.m_rndr;
    m_wnd = wnd.m_wnd;
    m_x = wnd.m_x;
    m_y = wnd.m_y;
    m_width = wnd.m_width;
    m_height = wnd.m_height;

    wnd.m_rndr = nullptr;
    wnd.m_wnd = nullptr;

    return *this;
}

Window::~Window()
{
    SDL_DestroyRenderer(m_rndr);
    SDL_DestroyWindow(m_wnd);

    LOG_DEBUG("Winow deleted succesfully\n");
}

Window* Window::create(const char *title)
{
    Window* wnd = new Window(title);
    std::uint32_t flags = SDL_WINDOW_SHOWN;

    if(0 > SDL_CreateWindowAndRenderer(wnd->m_width, wnd->m_height, flags,
                                       &(wnd->m_wnd), &(wnd->m_rndr))) {
        LOG_ERROR("Error! The window creating failed...\n");

        return nullptr;
    }

    SDL_SetWindowTitle(wnd->m_wnd, wnd->m_title.c_str());

    return wnd;
}

void Window::handleEvent()
{
    /* TODO: Initialize event handler */
}

void Window::show()
{
    SDL_ShowWindow(m_wnd);
}

void Window::update()
{
    SDL_RenderClear(m_rndr);
    SDL_RenderPresent(m_rndr);
}

bool Window::changeTitle(const char *title)
{
    if (nullptr == title) {
        LOG_ERROR("Invalid input: title = %s\n", title);

        return false;
    }

    m_title = title;

    SDL_SetWindowTitle(m_wnd, title);

    return true;
}

bool Window::resize(int w, int h)
{
    if (w < 0 || h < 0) {
        LOG_ERROR("Invalid input: w = %d, h = %d\n", w, h);

        return false;
    }

    m_width = w;
    m_height = h;

    SDL_SetWindowSize(m_wnd, w, h);

    return true;
}

bool Window::setPos(int x, int y)
{
    if (x < 0 || y < 0) {
        LOG_ERROR("Invalid input: x = %d, y = %d\n", x, y);

        return false;
    }

    m_x = x;
    m_y = y;

    SDL_SetWindowPosition(m_wnd, x, y);

    return true;
}

