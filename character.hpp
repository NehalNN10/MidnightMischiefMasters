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
        bool flag = true;
    protected:
        // for animations
        int frame;
        SDL_Rect* frames = new SDL_Rect[4];

        int x_jump = 20;
        int y_jump = 75;

    public:
        int gravity = 0;
        int currentY = 400;
        // source and mover rectangle
        SDL_Rect srcRect, moverRect;
        Map graph;

        void draw();
        void animation();
        bool isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const Map& map);
        void move(char direction);
};
