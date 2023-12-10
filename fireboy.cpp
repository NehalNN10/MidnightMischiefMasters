#include <iostream>
#include "fireBoy.hpp"

fireBoy::fireBoy()
{  
    std::cout<<"fireBoy Ctor Called\n";

    // four different animation types
    frames[0] = {32, 30, 120, 136};
    frames[1] = {224, 30, 120, 136};
    frames[2] = {416, 38, 120, 128};
    frames[3] = {608, 30, 120, 136};

    // first animation at start
    frame = 0;
    srcRect = frames[0];

    // default co-ords to spawn character
    moverRect = {850, 400, 50, 50};
}

fireBoy::~fireBoy()
{
    std::cout<<"fireBoy Dtor Called\n";
    // should delete here?
} 

void fireBoy::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assetOne, &srcRect, &moverRect);
}