#include <SDL.h>
#include "character.hpp"
#include "fireboy.hpp"
#include "watergirl.hpp"
#include "collectibles.hpp"
#include "paper1.hpp"

class MidMischief {

    private:
        SDL_Window *gwindow;
        // dynamically created for virual and polymorphic behaviour
        character *one = new fireboy();
        character *two = new watergirl();
        collectibles *first = new paper1();
        char direction_1;
        char direction_2;
        bool paused;

    public:
        MidMischief();
        void drawchars();
        void animatechars();
        void movechars(const Uint8* keystates);
        bool checkCollision();
        bool getpaused();
        void toggle_paused(bool p);
};