#include "watergirl.hpp"

watergirl::watergirl() : character({779, 0, 294, 848},{0,0,50,50}){} //default spawning location

void watergirl::move(SDL_Keycode key) { // movement of second character done using WASD
    if (key == SDLK_w){
        if (moverRect.y-20 > 0)moverRect.y -= 20;
        //else moverRect.y = 0;
    }
    else if (key == SDLK_s){
        if (moverRect.y+20 < 550) moverRect.y += 20;
    }
    else if (key == SDLK_d){
        if (moverRect.x+5 < 950) moverRect.x += 50;
    }
    else if (key == SDLK_a){
        if (moverRect.x-5 > 0) moverRect.x -= 50;
    }
    // moverRect.x += 2;
    // moverRect.y += 3;
}