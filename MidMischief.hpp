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

    public:
        MidMischief();
        void drawchars();
        void animatechars();
        void movechars(SDL_Keycode key);
        bool checkCollision();

};