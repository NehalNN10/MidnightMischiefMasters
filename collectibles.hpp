#pragma once
#include <SDL.h>

class collectibles{
    protected:
        // for animations
        int frame;
        SDL_Rect* frames = new SDL_Rect[15];

    public:
        // source and mover rectangle
        SDL_Rect srcRect, moverRect;

        void draw();
        void animation();
    
};