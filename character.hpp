#pragma once
#include <SDL.h>
#include "position.hpp"
#include "speed.hpp"

class character {
private:
    position *p;
    speed *s;

public:
    // made everything public for now
    SDL_Rect srcRect, moverRect;

    character(SDL_Rect src, SDL_Rect mover);
    // void draw();
    virtual void move() = 0;
};
