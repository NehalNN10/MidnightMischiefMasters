#pragma once
#include <SDL.h>
#include "position.hpp"
#include "speed.hpp"

class character {
private:
    position *p;
    speed *s;
protected:
    int x_jump = 5;
    int y_jump = 10;
public:
    // made everything public for now, should be private with their get set functions
    SDL_Rect srcRect;
    SDL_Rect moverRect;

    // character(SDL_Rect src, SDL_Rect mover);
    void draw(); // not working right now. 
    virtual void move(SDL_Keycode key) = 0; // pure virtual function //this was not commented but commented this down
};
