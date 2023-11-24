#include <SDL.h>
#include "character.hpp"
#include "fireboy.hpp"
#include "watergirl.hpp"

class MidMischief {

    private:
        SDL_Window *gwindow;
        // dynamically created for virual and polymorphic behaviour
        character *one = new fireboy();
        character *two = new watergirl();
        bool paused = false;
        // handling multi-input movement
        char direction_1;
        char direction_2;

    public:
        MidMischief();
        void drawchars();
        void animatechars();
        void movechars(SDL_Keycode key);
        bool checkCollision();
        bool getpaused(){ return paused; };
        void toggle_paused(){ paused = !paused; }

};