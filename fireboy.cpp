#include "fireboy.hpp"
#include <iostream>

 //default co-ords to spawn character
fireboy::fireboy()
{
    srcRect = {779, 0, 294, 848};
    moverRect = {0, 0, 50, 50};
}

// movement of one character done using arrow keys
void fireboy::move(SDL_Keycode key) 
{
    if (key == SDLK_UP)
    {
        if (moverRect.y-y_jump > 0) moverRect.y -= y_jump;
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