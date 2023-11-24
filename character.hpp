#pragma once
#include <SDL.h>
#include "position.hpp"
#include "speed.hpp"

class character 
{
    private:
        position *p;
        speed *s;
    protected:
        // for animations
        int frame;
        SDL_Rect* frames = new SDL_Rect[4];

        int x_jump = 20; //set to 20 for testing purposes
        int y_jump = 20; //set to 20 for testing purposes

    public:
        // source and mover rectangle
        SDL_Rect srcRect, moverRect;

        void draw();
        void animation();
        void move(char direction);
};
