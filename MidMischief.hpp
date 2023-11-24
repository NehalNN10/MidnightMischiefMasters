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
        // bool paused;
        // handling multi-input movement
        char direction_1;
        char direction_2;

    public:
        MidMischief();
        void drawchars();
        void animatechars();
        bool paused = false;
        void movechars(const Uint8* keystates);
        bool checkCollision();
        bool getpaused();
        void toggle_paused(bool p);

};