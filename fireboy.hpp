#include <SDL.h>
#include "character.hpp"

class fireboy : public character {
    public:
        fireboy();
        void move(SDL_Keycode key);
};