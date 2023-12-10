#include <iostream>
#include "collectibles.hpp"

collectibles::collectibles() 
{
    std::cout<<"collectibles Ctor Called\n";
    collected = false;
}

collectibles::~collectibles()
{
    std::cout<<"collectibles Dtor Called\n";
    // delete all the attributes here, change it all to dynamic and delete them
    // delete all the 15 frames as well
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