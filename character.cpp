#include <iostream>
#include "character.hpp"
#include "drawing.hpp"

void character::draw() 
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
