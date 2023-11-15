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
    SDL_Rect srsRect, moverRect;

    character(SDL_Rect srs, SDL_Rect mover);
    void draw();
    virtual void move() = 0;
};
