#pragma once
#include <SDL.h>
#include "map.hpp"
#include "drawing.hpp"

class character 
{
    private:
        bool flag;
        int jumpX;
        int jumpY;
        int gravity;

    protected:
        // for animations
        int frame;
        SDL_Rect* frames;
        
    public:
        int currentY;
        // source and mover rectangle
        SDL_Rect srcRect, moverRect;

        character();
        ~character();
        virtual void draw(); // for polymorphism
        void animation(); // derived objects also use this function.
        bool isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const map* map);
        void move(char direction, map* levelMap); // actual movement for characters
        void printCurrentPosition();
};
