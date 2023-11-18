#include "watergirl.hpp"

watergirl::watergirl() : character({779, 0, 294, 848},{0,0,50,50}){} //default spawning location

void watergirl::move(SDL_Keycode key) { // movement of second character done using WASD
    if (key == SDLK_w){
        if (moverRect.y-y_jump > 0)moverRect.y -= y_jump;
        //else moverRect.y = 0;
    }
    else if (key == SDLK_s){
        if (moverRect.y+y_jump < 550) moverRect.y += y_jump;
    }
    else if (key == SDLK_d){
        if (moverRect.x+x_jump < 950) moverRect.x += x_jump;
    }
    else if (key == SDLK_a){
        if (moverRect.x-x_jump > 0) moverRect.x -= x_jump;
    }
    // moverRect.x += 2;
    // moverRect.y += 3;
}