#include "fireboy.hpp"

fireboy::fireboy() : character({779, 0, 294, 848},{0,0,50,50}){} //default co-ords to spawn character

void fireboy::move(SDL_Keycode key) { // movement of one character done using arrow keys
    
    if (key == SDLK_UP){
        if (moverRect.y-y_jump > 0)moverRect.y -= y_jump;
        //else moverRect.y = 0;
    }
    else if (key == SDLK_DOWN){
        if (moverRect.y+y_jump < 550) moverRect.y += y_jump;
    }
    else if (key == SDLK_RIGHT){
        if (moverRect.x+x_jump < 950) moverRect.x += x_jump;
    }
    else if (key == SDLK_LEFT){
        if (moverRect.x-x_jump > 0) moverRect.x -= x_jump;
    }
    
    // moverRect.x += 3;
    // moverRect.y += 2;
}