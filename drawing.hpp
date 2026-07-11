#pragma once
#include<SDL.h>

class Drawing
{
    public:
        static SDL_Renderer* gRenderer;
        static SDL_Texture* assetOne;
        static SDL_Texture* assetTwo;
        static SDL_Texture* paperOne;
        static SDL_Texture* brickTexture; // Add this line!
};