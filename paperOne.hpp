#include <SDL.h>
#include "collectibles.hpp"

class paperOne : public collectibles
{
    public:
        paperOne(SDL_Rect mR);
        ~paperOne();

};