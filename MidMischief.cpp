#include "MidMischief.hpp"
#include "drawing.hpp"
#include "iostream"

MidMischief::MidMischief() {}

void MidMischief::drawchars()
{
    one->draw();
    two->draw();
    first->draw();
}

void MidMischief::movechars(SDL_Keycode key) 
{
    // if ( key == SDLK_w || key == SDLK_a || key == SDLK_s || key == SDLK_d ) 
    // {
        two->move(key);
    // }
    // else if ( key == SDLK_UP || key == SDLK_DOWN || key == SDLK_LEFT || key == SDLK_RIGHT )
    // {
        one->move(key);
    // }
}

void MidMischief::animatechars()
{
    one->animation();
    two->animation();
    first->animation();
}
// for now checks if characters are colliding, need to convert and add collectables
bool MidMischief::checkCollision()
{
    //The sides of the rectangles
    int leftA, leftB, leftP1;
    int rightA, rightB, rightP1;
    int topA, topB, topP1;
    int bottomA, bottomB, bottomP1;

    //Calculate the sides of rect A
    leftA = one->moverRect.x;
    rightA = one->moverRect.x + one->moverRect.w;
    topA = one->moverRect.y;
    bottomA = one->moverRect.y + one->moverRect.h;

    //Calculate the sides of rect B
    leftB = two->moverRect.x;
    rightB = two->moverRect.x + two->moverRect.w;
    topB = two->moverRect.y;
    bottomB = two->moverRect.y + two->moverRect.h;

    //Calculate the sides for collecteble item

    leftP1 = first->moverRect.x;
    rightP1 = first->moverRect.x + first->moverRect.w;
    topP1 = first->moverRect.y;
    bottomP1 = first->moverRect.y + first->moverRect.h;

    if( bottomA <= topP1 && bottomB <= topP1 )
    {
        return false;
    }

    if( topA >= bottomP1 && topB >= bottomP1 )
    {
        return false;
    }

    if( rightA <= leftP1 && rightB <= leftP1 )
    {
        return false;
    }

    if( leftA >= rightP1 && leftB >= rightP1 )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
