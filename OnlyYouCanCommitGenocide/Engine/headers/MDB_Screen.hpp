#ifndef MDB_SCREEN_H
#define MDB_SCREEN_H

#include "../include/SDL2/SDL.h"

#include "exceptions/MDB_exception.hpp"

#define GLEW_STATIC
#include "../include/GL/glew.h"
#include "../include/GL/wglew.h"


class MDB_Screen
{
private:
    SDL_Window* l_window;
    SDL_GLContext l_gl_context;
    SDL_Renderer* l_renderer;

public:
    MDB_Screen(int width, int height, Uint32 window_flags, Uint32 rend_flags);
    ~MDB_Screen();

    void set_screen_colour(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

};

#endif