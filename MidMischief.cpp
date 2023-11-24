#include "MidMischief.hpp"
#include "drawing.hpp"
#include "iostream"

MidMischief::MidMischief() {}

void MidMischief::drawchars()
{
    one->draw();
    two->draw();
}


//asynchronous movement achieved
void MidMischief::movechars(SDL_Keycode key) 
{
    switch(key)
    {
        case SDLK_w:
            direction_1 = 'U';
            break;
        case SDLK_s:
            direction_1 = 'D';
            break;
        case SDLK_a:
            direction_1 = 'L';
            break;
        case SDLK_d:
            direction_1 = 'R';
            break;
        case SDLK_UP:
            direction_2 = 'U';
            break;
        case SDLK_DOWN:
            direction_2 = 'D';
            break;
        case SDLK_LEFT:
            direction_2 = 'L';
            break;
        case SDLK_RIGHT:
            direction_2 = 'R';
            break;
    }
    two->move(direction_1); //passing in characters as they take less space than sdlkey objects 
    one->move(direction_2);
}

void MidMischief::animatechars()
{
    one->animation();
    two->animation();
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
