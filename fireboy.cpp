#include "fireboy.hpp"
#include <iostream>

fireboy::fireboy()
{
    frame = 0;
    // four different animation types
    frames[0] = {32, 30, 120, 136};
    frames[1] = {224, 30, 120, 136};
    frames[2] = {416, 38, 120, 128};
    frames[3] = {608, 30, 120, 136};

    srcRect = frames[0];
    // default co-ords to spawn character
    moverRect = {850, 400, 50, 50};
}

// movement of one character done using arrow keys
void fireboy::move(SDL_Keycode key) 
{
    if (key == SDLK_UP)
    {
        if (moverRect.y-y_jump > 0 && fireboy::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y-y_jump, graph)) 
        moverRect.y -= y_jump;
    }
    else if (key == SDLK_DOWN)
    {
        if (moverRect.y+y_jump < 550) moverRect.y += y_jump;
    }
    else if (key == SDLK_RIGHT)
    {
        if (moverRect.x+x_jump < 950) moverRect.x += x_jump;
    }
    else if (key == SDLK_LEFT)
    {
        if (moverRect.x-x_jump > 0) moverRect.x -= x_jump;
    }
}