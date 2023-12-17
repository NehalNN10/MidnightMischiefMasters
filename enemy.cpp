#include "enemy.hpp"
#include <iostream>

enemy::enemy()
{  
    std::cout<<"enemy Ctor Called\n";

    // four different animation types
    frames[0] = {32, 30, 120, 136};
    frames[1] = {224, 30, 120, 136};
    frames[2] = {416, 38, 120, 128};
    frames[3] = {608, 30, 120, 136};

    // first animation at start
    frame = 0;
    srcRect = frames[frame];

    // default co-ords to spawn character
    moverRect = {0, 0, 50, 50};
}

enemy::~enemy()
{
    std::cout<<"enemy Dtor Called\n";
    delete[] frames;
    frames = nullptr;
} 

void enemy::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assetOne, &srcRect, &moverRect);
}