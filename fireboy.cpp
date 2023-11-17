#include "fireboy.hpp"

fireboy::fireboy() : character({779, 0, 294, 848},{0,0,50,50}){} //default co-ords to spawn character

void fireboy::move(SDL_Keycode key) { // movement of one character done using arrow keys
    
    if (key == SDLK_UP){
        if (moverRect.y-20 > 0)moverRect.y -= 20;
        //else moverRect.y = 0;
    }
    else if (key == SDLK_DOWN){
        if (moverRect.y+20 < 550) moverRect.y += 20;
    }
    else if (key == SDLK_RIGHT){
        if (moverRect.x+5 < 950) moverRect.x += 50;
    }
    else if (key == SDLK_LEFT){
        if (moverRect.x-5 > 0) moverRect.x -= 50;
    }
    
    // moverRect.x += 3;
    // moverRect.y += 2;
}