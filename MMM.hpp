#include <SDL.h>
#include "character.hpp"
#include "fireboy.hpp"
#include "watergirl.hpp"

class MMM {

    private:
        SDL_Window *gwindow;
        fireboy one;
        watergirl two;

    public:
        MMM();
        void draw(SDL_Renderer* gRenderer, SDL_Texture* assets, SDL_Keycode key, Uint32 eventType);

};