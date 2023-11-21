#include <iostream>
#include "character.hpp"
#include "drawing.hpp"

void character::draw() 
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void character::animation()
{
    frame = (frame + 1) % 4;
    srcRect = frames[frame];
}
