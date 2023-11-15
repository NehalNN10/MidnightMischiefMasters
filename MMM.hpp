#include <SDL.h>
#include "character.hpp"
#include "fireboy.hpp"
#include "watergirl.hpp"

class MMM {

    private:
        SDL_Window *gwindow;
        fireboy one;
        watergirl two;

    public: // making everything public for now
        MMM();
        void draw();
};