#pragma once
#include <SDL.h>
#include "drawing.hpp"

class collectibles
{
    protected:
        // for animations
        int frame;
        SDL_Rect* frames = new SDL_Rect[15];

    public:
        // source and mover rectangle
        SDL_Rect srcRect, moverRect;

        bool collected;

        collectibles();
        ~collectibles();
        void draw();
        void animation();
};