#include "MidMischief.hpp"
#include "drawing.hpp"
#include "iostream"

MidMischief::MidMischief() {}

void MidMischief::drawchars()
{
    one->draw();
    two->draw();
}

void MidMischief::movechars(SDL_Keycode key, Uint32 eventType) 
{
    // if(eventType == SDL_KEYDOWN){ //if key is pressed only then movement is called.
    if ( key == SDLK_w || key == SDLK_a || key == SDLK_s || key == SDLK_d ) 
    {
        two->move(key);
    }
    else if ( key == SDLK_UP || key == SDLK_DOWN || key == SDLK_LEFT || key == SDLK_RIGHT )
    {
        one->move(key);
    }
}
