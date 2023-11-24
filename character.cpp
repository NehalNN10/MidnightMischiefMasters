#include <iostream>
#include "character.hpp"
#include "drawing.hpp"

// draws character
void character::draw() 
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

// changes animation of character
void character::animation()
{
    frame = (frame + 1) % 4;
    srcRect = frames[frame];
}

void character::move(char direction)
{
    if (direction == 'U')
    {
        if (moverRect.y - y_jump > 0)
            moverRect.y -= y_jump;
    }
    else if (direction == 'D')
    {
        if (moverRect.y + y_jump < 550)
            moverRect.y += y_jump;
    }
    else if (direction == 'R')
    {
        if (moverRect.x + x_jump < 950)
            moverRect.x += x_jump;
    }
    else if (direction == 'L')
    {
        if (moverRect.x - x_jump > 0)
            moverRect.x -= x_jump;
    }
}
