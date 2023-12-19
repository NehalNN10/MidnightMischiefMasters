#pragma once
#include <SDL.h>
#include "drawing.hpp"

class collectibles
{
    protected:
        // for animations
        int frame;
        SDL_Rect* frames;

    public:
        // source and mover rectangle
        SDL_Rect srcRect, moverRect;
        // if that collectible is collected
        bool collected;

        collectibles(); // ctor
        ~collectibles(); // dtor
        void draw();
        void animation();
};