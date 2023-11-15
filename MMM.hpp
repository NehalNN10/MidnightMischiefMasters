#include <SDL.h>
#include "character.hpp"
#include "fireboy.hpp"
#include "watergirl.hpp"

class MMM {
    public: // making everything public for now
        SDL_Window *gwindow = NULL;
        fireboy one;
        watergirl two;          
};