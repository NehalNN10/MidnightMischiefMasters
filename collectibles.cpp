#include <iostream>
#include "collectibles.hpp"

collectibles::collectibles() 
{
    std::cout<<"collectibles Ctor Called\n";
    collected = false; // false at the start
    frames = new SDL_Rect[9]; // animation frames
}

collectibles::~collectibles()
{
    std::cout<<"collectibles Dtor Called\n";
    delete[] frames; // deleted in heap
    frames = nullptr; // no dangling pointer
}
// drawing that paperOne
void collectibles::draw() 
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::paperOne, &srcRect, &moverRect);
}

// changes animation of collectibles
void collectibles::animation()
{
    frame = (frame + 1) % 9;
    srcRect = frames[frame];
}