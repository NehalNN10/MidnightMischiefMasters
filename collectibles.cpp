#include <iostream>
#include "collectibles.hpp"

collectibles::collectibles() 
{
    std::cout<<"collectibles Ctor Called\n";
    collected = false;
    frames = new SDL_Rect[9];
}

collectibles::~collectibles()
{
    std::cout<<"collectibles Dtor Called\n";
    delete[] frames;
    std::cout << "Error here?" << std::endl;
    frames = nullptr;
}

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