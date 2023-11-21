#include <SDL.h>
#include "character.hpp"
#include "fireboy.hpp"
#include "watergirl.hpp"

class MMM {

    private:
        SDL_Window *gwindow;
        character *one = new fireboy();
        character *two = new watergirl();

    public:
        MMM();
        // void drawchars();
        void drawchars();

        void movechars(SDL_Keycode key, Uint32 eventType);

};