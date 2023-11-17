#pragma once
#include <SDL.h>
#include "position.hpp"
#include "speed.hpp"

class character {
private:
    position *p;
    speed *s;

public:
    // made everything public for now, should be private with their get set functions
    SDL_Rect srcRect, moverRect;

    character(SDL_Rect src, SDL_Rect mover);
    // void draw(); // not working right now. //this was not commented but commented this down
    //virtual void move() = 0; // pure virtual function
};
