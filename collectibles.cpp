#include <iostream>
#include "collectibles.hpp"
#include "drawing.hpp"


collectibles::collectibles() 
{
    collected = false;
}

void collectibles::draw() 
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::collect, &srcRect, &moverRect);
}

// changes animation of collectibles
void collectibles::animation()
{
    frame = (frame + 1) % 15;
    srcRect = frames[frame];
}