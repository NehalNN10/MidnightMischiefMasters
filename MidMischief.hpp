#include <SDL.h>
#include "character.hpp"
#include "fireboy.hpp"
#include "watergirl.hpp"

class MidMischief {

    private:
        SDL_Window *gwindow;
        character *one = new fireboy();
        character *two = new watergirl();

    public:
        MidMischief();
        void drawchars();
        void animatechars();
        void movechars(SDL_Keycode key);

};