#pragma once
#include <SDL.h>
#include "position.hpp"
#include "speed.hpp"

class character 
{
    // not much work for this right now
    private:
        position *p;
        speed *s;
    protected:
        // source and mover rectangle
        SDL_Rect srcRect, moverRect;
        // for animations
        int frame;
        SDL_Rect* frames = new SDL_Rect[4];

        int x_jump = 5;
        int y_jump = 10;

    public:
        void draw();
        void animation();
        virtual void move(SDL_Keycode key) = 0; // pure virtual function
};
