#pragma once
#include<SDL.h>

class Drawing{
    public:
        //The window renderer
        static SDL_Renderer* gRenderer;
        //global reference to png image sheets
        static SDL_Texture* assets;
        static SDL_Texture* collect;
};
