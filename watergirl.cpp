#include "watergirl.hpp"
#include <iostream>


watergirl::watergirl() 
{    
    frame = 0;
    // four different animation types
    frames[0] = {32, 30, 120, 136};
    frames[1] = {224, 30, 120, 136};
    frames[2] = {416, 38, 120, 128};
    frames[3] = {608, 30, 120, 136};

    srcRect = frames[0];
    // default co-ords to spawn character
    moverRect = {50, 400, 50, 50};
}

// movement of second character done using WASD
void watergirl::move(SDL_Keycode key) {
    if (key == SDLK_w)
    {
        if (moverRect.y-y_jump > 0 && watergirl::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y-y_jump, graph)) 
            moverRect.y -= y_jump;
    }
    else if (key == SDLK_s)
    {
        if (moverRect.y+y_jump < 550 && watergirl::isMoveValid(moverRect.x, moverRect.y, moverRect.x, moverRect.y+y_jump, graph))
            moverRect.y += y_jump;
    }
    else if (key == SDLK_d)
    {
        if (moverRect.x+x_jump < 950 && watergirl::isMoveValid(moverRect.x, moverRect.y, moverRect.x + x_jump, moverRect.y, graph)) 
            moverRect.x += x_jump;
    }
    else if (key == SDLK_a)
    {
        if (moverRect.x-x_jump > 0 && watergirl::isMoveValid(moverRect.x, moverRect.y, moverRect.x - x_jump, moverRect.y, graph)) 
            moverRect.x -= x_jump;
    }
}

