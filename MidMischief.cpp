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
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

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

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
