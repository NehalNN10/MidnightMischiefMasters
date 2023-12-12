#pragma once
#include <SDL.h>
#include "map.hpp"
#include "drawing.hpp"

class character 
{
    private:
        bool flag = true;
        int jumpX = 20;
        int jumpY = 75;

    protected:
        // for animations
        int frame;
        SDL_Rect* frames = new SDL_Rect[4];

    public:
        int gravity = 0;
        int currentY = 400;

        // source and mover rectangle
        SDL_Rect srcRect, moverRect;
        map graph;

        character();
        ~character();
        virtual void draw();
        void animation();
        bool isMoveValid(int currentX, int currentY, int destinationX, int destinationY, const map& map);
        void move(char direction);
        bool jump_available();
        void apply_gravity();
        bool getleft(){return left;}
        void setleft(bool x){left = x;};
        bool getright(){return right;}
        void setright(bool x){right = x;}
        int getJumpX(){ return jumpX; }
        // void othermove();
};
