#pragma once
#include <SDL.h>
#include "map.hpp"
#include "drawing.hpp"

#include "collectibles.hpp"
#include "collisionClass.hpp"

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
        float y_velocity = 0.0f;
        bool isJumping = false;
        const float GRAVITY = 1.2f;
        int animCounter = 0;
        
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
        bool operator == (const collectibles *c); // operator overloading of the equality operator
        void applyGravity(); // Add this line under public
};
