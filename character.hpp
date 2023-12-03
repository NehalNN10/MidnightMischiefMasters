#pragma once
#include <SDL.h>
#include "position.hpp"
#include "speed.hpp"
#include "Map.hpp"

class character 
{
    private:
        position *p;
        speed *s;
    protected:
        // for animations
        int frame;
        SDL_Rect* frames = new SDL_Rect[4];

        int x_jump = 20;
        int y_jump = 20;

    public:
        int gravity = 0;
        // source and mover rectangle
        SDL_Rect srcRect, moverRect;
        Map graph;

        void draw();
        void animation();
        bool isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const Map& map);
        void move(char direction);
};
