#include <SDL.h>
#include "collectibles.hpp"

class paperOne : public collectibles // inheritance
{
    public:
        paperOne(SDL_Rect mR); // param ctor
        ~paperOne(); // dtor
};